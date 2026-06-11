#include<cstdio>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
    if(a+b>=c) return puts("No"),0;
    long long x=4ll*(a*1ll)*(1ll*b);
    long long y=a*1ll*a+b*1ll*b+c*1ll*c+2ll*a*b-2ll*a*c-2ll*b*c;
    x<y?puts("Yes"):puts("No");
    return 0;
}