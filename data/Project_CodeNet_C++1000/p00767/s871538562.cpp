#include <cstdio>
int m,M,X,Y,x,y,i,j;
main(){
while(scanf("%d%d",&x,&y),x||y){
m=x*x+y*y,M=90000;
for(i=150;i;i--)for(j=i+1;j<=150;j++) if(m==i*i+j*j&&x<i) M=i*i+j*j,X=i,Y=j;else if(m<i*i+j*j&&M>=i*i+j*j)M=i*i+j*j,X=i,Y=j;
printf("%d %d\n",X,Y);
}
}