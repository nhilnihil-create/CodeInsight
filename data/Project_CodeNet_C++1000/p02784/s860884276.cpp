#include <stdio.h> 

int main() 

{
long int a,b,i,m,n=0;
scanf("%ld %ld",&a,&b); 

for(i=1;i<=b;i++) 
{
scanf("%ld",&m);
n=n+m; 
}
if(n>=a)
{
printf("Yes\n");
}
else
printf("No\n"); 
return 0; 
}   