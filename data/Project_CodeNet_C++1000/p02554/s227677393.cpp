#include<cstdio>
#include<set>
#include<stack>
#include<queue>
int main()
{
int al=1000000007;
long long int n,x,y,z,ans;
x=y=z=1;
scanf("%lld",&n);
for(int i=0;i<n;i++)
{
x=x*10;
y=y*9;
z=z*8;
x=(x+al)%al;
y=(y+al)%al;
z=(z+al)%al;
}
ans=x-y-y+z;
ans=(ans+al+al)%al;
printf("%lld",ans);
}