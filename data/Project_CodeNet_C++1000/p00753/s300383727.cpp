#include<stdio.h>

int main(){
int n;
bool F[246914];

for(int i=0;i<246914;i++)
for(int j=2;j*j<=i;j++){
if(i%j==0){F[i]=false;break;}
else if(i%j!=0)F[i]=true;}

F[2]=true;F[3]=true;
while(1){
scanf("%d",&n);if(n==0)break;
int c=0;
for(int i=n+1;i<=2*n;i++)
	if(F[i]==true){c++;}//printf("%d",i);}
printf("%d\n",c);
}

return 0;
}