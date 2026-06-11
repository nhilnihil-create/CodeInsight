#include<cstdio>
#include<cmath>
#define RI register int
using namespace std;
const int LIM=1e9;
long long s; int a,b,c,d;
int main()
{
    scanf("%lld",&s); a=d=(int)sqrt(s);
    while (1LL*a*d<s) if (a<d) ++a; else ++d;
    long long left=1LL*a*d-s; for (RI i=1;1LL*i*i<=left;++i)
    if (left%i==0&&i<=LIM&&left/i<=LIM) { b=i; c=left/i; break; }
    return printf("0 0 %d %d %d %d",a,b,c,d),0;
}