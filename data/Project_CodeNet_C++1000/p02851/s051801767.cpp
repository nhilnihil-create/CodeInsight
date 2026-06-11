#include<map>
#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
int a[200050];
int b[200050];
int main(void)
{
    int k, n, t;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        a[i] = t;
    }
    map<ll, ll> cnt;
    ll tot = 0, s = 1;
    for(int i = 0; i <= n; ++i)
    {
        s += a[i];
        ll x = (s - i) %k;
        b[i] = x;
        if (i - k >= 0)
            cnt[b[i - k]]--;
        tot += cnt[x];
        cnt[x] += 1;
    }
    cout<<tot<<endl;
    return 0;
}
