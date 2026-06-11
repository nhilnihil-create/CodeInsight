#include<cstdio>
#include<set>
#include<stack>
#include<queue>
int main()
{
long long int a,b,c,d,x,ans;
scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
ans=a*c;
x=a*d;
if(ans<x){ans=x;}
x=b*c;
if(ans<x){ans=x;}
x=b*d;
if(ans<x){ans=x;}
printf("%lld",ans);

}