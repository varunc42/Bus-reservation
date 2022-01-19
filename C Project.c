#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int no;
void bus();
void name_number(int booking,char numstr[100]);
void booking();
int read_number(int no);
void read_name(int no);
void status();
void status_1(int no);
void cancle();

int main()
{
    int num,i;
    do{
    system("cls");
    printf("-------------------------------------------\n");
    printf("               BUS RESERVATION\n");
    printf("-------------------------------------------\n");
    printf("---------------  MAIN MENU  ---------------\n");
    printf(" [1] Book Tickets\n");
    printf(" [2] Cancel Booking\n");
    printf(" [3] Bus Status Board\n");
    printf(" [4] Exit\n");
    printf("-------------------------------------------\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        booking();
        break;
    case 2:
        cancle();
        break;
    case 3:
        status();
        break;
    }
getch();
    }
    while(num != 4);
    system("CLS");
    printf("------------------------------------------------\n");
    printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM\n");
    printf("------------------------------------------------\n");
    getch();
    return 0;
}

void booking()
{
    int i=0;
    char numstr[100];
system("cls");
printf("-------------------------------------------\n");
printf("             BUS RESERVATION\n");
printf("-------------------------------------------\n");
printf(" [1] SS Travels\n");
printf(" [2] Orange Travels\n");
printf(" [3] Morning Star\n");
printf(" [4] Citizen Tours\n");
printf(" [5] SRT Travels\n");
printf("-------------------------------------------\n");
printf("ENTER THE BUS NUMBER: ");
scanf("%d",&no);
system("cls");
printf("-------------------------------------------\n");
printf("          BUS RESERVATION\n");
printf("-------------------------------------------\n");
status_1(no);
FILE *f1, *fopen();
char str1[80]="32",str2[4],str3[4];
int seat1,seat2,booking=0;
if(no == 1)
{
f1 = fopen("tr1.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(no == 2)
{
f1 = fopen("tr2.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(no == 3)
{
f1 = fopen("tr3.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(no == 4)
{
f1 = fopen("tr4.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
else if(no == 5)
{
f1 = fopen("tr5.txt","r+");
fgets(str1,80,f1);
fclose(f1);
}
seat1=atoi(str1);
if(seat1 <= 0)
{
printf("There is no blank seat in this bus ");
}
else
{
printf("-------------------------------------------\n");
printf("AVAILABLE SEATS: %d\n",seat1);
printf("NUMBER OF TICKETS: ");
scanf("%d",&booking);
seat1=seat1-booking;
itoa(no,numstr,10);
name_number(booking,numstr);
printf("The Total booking amount is %d",2000*booking);
itoa(seat1, str1, 10);
if(no == 1)
{
f1 = fopen("tr1.txt","w");
fputs(str1,f1);
fclose(f1);
}
else if(no == 2)
{
f1 = fopen("tr2.txt","w");
fputs(str1,f1);
  fclose(f1);
}
else if(no == 3)
{
f1 = fopen("tr3.txt","w");
fputs(str1,f1);
  fclose(f1);
}
else if(no == 4)
{
f1 = fopen("tr4.txt","w");
fputs(str1,f1);
  fclose(f1);
}
else if(no == 5)
{
f1 = fopen("tr5.txt","w");
fputs(str1,f1);
fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");
   b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)
{
      printf("------------- Enter the details for ticket no %d --------------\n\n",i+1);
      printf("ENTER THE SEAT NUMBER: ");
      scanf("%d",&number);
      printf("ENTER THE PERSON NAME: ");
      scanf("%s",name[number-1]);
      printf("-------------------------------------------\n");
      printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int no)
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(no,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int no)
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(no,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
    printf("-------------------------------------------\n");
    printf("          BUS RESERVATION\n");
    printf("-------------------------------------------\n");
    int i,no,index=0,j;
printf(" [1] SS Travels\n");
printf(" [2] Orange Travels\n");
printf(" [3] Morning Star\n");
printf(" [4] Citizen Tours\n");
printf(" [5] SRT Travels\n");
printf("-------------------------------------------\n");
    printf(" ENTER THE BUS NUMBER: ");
    scanf("%d",&no);
    j=read_number(no);
    read_name(no);
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int no)
{
    system("cls");
    printf("-------------------------------------------\n");
    printf("       BUS RESERVATION\n");
    printf("-------------------------------------------\n");
    int i,index=0,j;
    j=read_number(no);
    read_name(no);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
int seat_no,i,j;
char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
printf("ENTER THE BUS NUMBER: ");
scanf("%d",&no);
itoa(no,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
strcat(tempstr2,numstr);
read_number(no);
read_name(no);
status_1(no);
printf("-------------------------------------------\n");
printf("ENTER THE SEAT NUMBER: ");
scanf("%d",&seat_no);
FILE *a,*b;
a = fopen(tempstr1,"w+");
b = fopen(tempstr2,"w+");
for(i=0; i<32; i++)
{
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
}
fclose(a);
fclose(b);
printf("\n");
printf("------------------------------------------------------------\n");
printf("  Your 2000 Rupees have been Transfered to your Bank Account\n");
printf("------------------------------------------------------------\n");
}


