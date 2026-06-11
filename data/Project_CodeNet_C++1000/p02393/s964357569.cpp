#include<stdio.h>

int main(void)
{
int num[3];
int i,j,tmp;

for(i=0;i<3;i++){
scanf("%d",&num[i]);
}

if(num[0]>num[1]){
tmp=num[0];
num[0]=num[1];
num[1]=tmp;
}

if(num[1]>num[2]){
tmp=num[1];
num[1]=num[2];
num[2]=tmp;
}

if(num[0]>num[1]){
tmp=num[0];
num[0]=num[1];
num[1]=tmp;
}

for(j=0;j<2;j++){
printf("%d ",num[j]);
}
printf("%d",num[2]);
printf("\n");

return 0;
}