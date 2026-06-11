#include <cstdio>
int m,M,X,Y,x,y,i,j;
main(){ while(scanf("%d%d",&x,&y),x||y){
m=x*x+y*y,M=90000;
for(i=150;i;i--)for(j=i+1;j<=150;j++){y=i*i+j*j;if(m==y&&x<i)M=y,X=i,Y=j;else if(m<y&&M>=y)M=y,X=i,Y=j;}
printf("%d %d\n",X,Y);}return 0;}