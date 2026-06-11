#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 105 + 5;
const int mod = 1e9 + 7;
ll ksm (ll a, ll b)
{
    ll ans = 1 , base = a;
    while (b)
    {
        if (b & 1) ans = ans * base % mod;
        b >>= 1;
        base = base * base % mod;
    }
    return ans;
}
ll C (ll a , ll b)
{
    ll up = 1 , down = 1;
    for (ll i = 0 ; i < b ; i++){
        (up *= (a - i)) %= mod;
        (down *= (b - i)) %= mod;
    }
    return up % mod * ksm(down , mod - 2) % mod;
}
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    ll n , a , b; cin >> n >> a >> b;
    ll ans = ksm(2 , n) % mod;
  //  cout << C(n , a) << " " << C(n , b) << endl;
    ans = (ans - C(n , a) + mod) % mod;
    ans = (ans - C(n , b) + mod) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}
