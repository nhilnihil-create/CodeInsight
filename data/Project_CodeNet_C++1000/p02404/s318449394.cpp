#include<cstdio>
int main(void){
int w;
int h;
for(;;){
scanf("%d %d",&w,&h);
if(w==0&&h==0)break;
else{
for(int i=0;i<h;i++)printf("#");
printf("\n");
for(int i=2;i<w;i++){
printf("#");
for(int j=2;j<h;j++)printf(".");
printf("#\n");
}
for(int i=0;i<h;i++)printf("#");
printf("\n\n");
}
}
return 0;
}