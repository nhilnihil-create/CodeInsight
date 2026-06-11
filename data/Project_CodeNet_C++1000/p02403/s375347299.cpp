#include<cstdio>

int main(void){
int H,W,i,j;
do {
scanf("%d%d",&H,&W);
if(H!=0||W!=0){
for(i=1;i<=H;i++){
for(j=1;j<=W;j++){
printf("#");}
printf("\n");}
printf("\n");}
}while(H!=0||W!=0);
return 0;
}