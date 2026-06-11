# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;

// long long A[1000000];
long long N,X,Y;
long long K[40000];
int main(void)
{
    // freopen("aaa.in","r",stdin);
    scanf("%lld%lld%lld",&N,&X,&Y);
    for (long long i=1;i<N;i++)
    {
        for (long long j=i+1;j<=N;j++)
        {
            int kk=min(j-i,abs(i-X)+abs(j-Y)+1);
            K[kk]++;
        }
    }
    for (int i=1;i<N;i++) printf("%lld\n",K[i]);
    return 0;
}