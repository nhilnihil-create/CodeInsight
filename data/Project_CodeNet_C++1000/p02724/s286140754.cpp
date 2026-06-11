# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
    long long x;
    scanf("%lld",&x);
    long long ans = x/500*1000;
    x%=500;
    ans+= x/5*5;
    printf("%lld\n",ans);
    return 0;
}