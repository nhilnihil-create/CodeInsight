#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;

ll n , k , gc[N] , mod=1e9+7 , ans;

ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

ll solve(ll num)
{
    ll tmp = fp(k/num,n); //3add el arkam elee divisble by num
    gc[num] = tmp;
    for(int i=num*2; i<=k; i+=num)
    {
        gc[num] -= gc[i];
        gc[num] = (gc[num]+mod)%mod;
    }
    return (gc[num]*num)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i=k; i>0; i--)
    {
        ans += solve(i);
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}