#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

ll mpow(ll a, ll b) {
    if(b == 0) return 1 % mod;
    ll x = mpow(a,b/2);
    x = (x*x)%mod;
    if(b&1) {
        x = (x * a) % mod;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    vll m(k + 1,0);
    for(ll i = k; i >= 1; i--) {
        ll res = mpow(k / i, n);
        for(ll j = i * 2; j <= k; j += i) {
            res = (res - m[j]) % mod;
            if(res < 0) res += mod;
        }
        ans += (i*res)%mod;
        ans %= mod;
        m[i] = res;
    }
    cout << ans << endl;
    return 0;
}
