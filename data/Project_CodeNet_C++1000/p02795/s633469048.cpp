#include<stdio.h>
int main()
{
int H,W,N;
int P=0,C=0;
scanf("%d", &H);
scanf("%d", &W);
scanf("%d", &N);
if(H > W)
{
    P = H;
}  
else
{
    P = W;
}
int i = 0; 
do
{
    C++;
    i = i +P;
}
while(i < N);
printf("%d\n",C);
return 0;
}
