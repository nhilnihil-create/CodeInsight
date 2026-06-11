#include<bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long ll;

ll ara[M];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%lld", ara+i);

    ll x = 0;
    for(int i = 1; i <= n; i++) x ^= ara[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            if((x&(1LL<<j)) && (ara[i]&(1LL<<j))) ara[i] ^= (1LL<<j);
        }
    }

    int curr = 1;
    for(int j = 59; j >= 0; j--)
    {
        int paisi = -1;

        for(int i = curr; i <= n; i++)
        {
            if(ara[i]&(1LL<<j))
            {
                paisi = i;
                break;
            }
        }

        if(paisi == -1) continue;

        swap(ara[curr], ara[paisi]);

        for(int i = curr+1; i <= n; i++)
        {
            if(ara[i]&(1LL<<j)) ara[i] ^= ara[curr];
        }
        curr++;
    }

    //for(int i = 1; i <= n; i++) printf("--> %lld\n", ara[i]);

    ll ans = 0;
    curr = 1;

    for(int j = 59; j >= 0; j--)
    {
        if(ara[curr]&(1LL<<j))
        {
            if((ans&(1LL<<j)) == 0) ans ^= ara[curr];
            curr++;
        }
    }

    ans *= 2;
    ans += x;

    printf("%lld\n", ans);

    return 0;
}
