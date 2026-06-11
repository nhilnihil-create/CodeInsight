#include<cstdio>

int main(void){
int H,W,i,j;
do {
scanf("%d%d",&H,&W);
if(H!=0||W!=0){
for(j=1;j<=W;j++){printf("#");}printf("\n");//1retume
for(i=2;i<=H-1;i++){
printf("#");
for(j=2;j<=W-1;j++){printf(".");}
printf("#\n");}//2karaH-1retume
for(j=1;j<=W;j++){printf("#");}printf("\n");
printf("\n");}
}while(H!=0||W!=0);
return 0;
}