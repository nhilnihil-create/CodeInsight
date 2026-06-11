#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long

#define pii pair < int, int >
#define pll pair < ll, ll >
#define pci pair < char, int >
#define psi pair < string, int >

#define vi vector < int >
#define vll vector < ll >
#define vs vector < string >
#define vc vector < char >
#define vpi vector < pii >
#define vpll vector < pll >

#define pb push_back

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

bool chkbit(ll n, ll k)
{
    return n & (1LL << k);
}

int main()
{
    fast;

    ll n;

    cin >> n;

    vll a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for(ll i = 0; i < 61; i++){
        ll cnt = 0;

        for(auto x : a) cnt += chkbit(x, i);

        ll tmp1 = (cnt * (n - cnt)) % mod;
        ll tmp2 = (1LL << i) % mod;
        ll tmp3 = (tmp1 * tmp2) % mod;
        ans += tmp3;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}

