# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;

long long A[1000000];
long long N,K;
int main(void)
{
    // freopen("aaa.in","r",stdin);
    scanf("%lld%lld",&K,&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&A[i]);
    }
    long long ans = A[1]+K-A[N];
    long long maxx = ans;
    for (int i=2;i<=N;i++)
    {
        ans+=A[i]-A[i-1];
        maxx = max(maxx,A[i]-A[i-1]);
    }
    printf("%lld\n",ans-maxx);
    return 0;
}