#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define fi first
#define se second
#define pi 3.141592653589793
#define mod 1000000007ll
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(), v.end(), greater<ll>()
#define tc int t;cin>>t;while(t--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g int tt;cin>>tt;for(int ti=1;ti<=tt;ti++)
#define case_g "Case #"<<ti<<": "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
using namespace std;
vl fact(200006);
ll modelus(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1ll) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll modinv(ll num) {
    return modelus(num, num - 2);
}
ll build_modinv() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 200005; ++i) {
        fact[i] = fact[mod % i]*(mod - mod / i) % mod;
    }
}
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ad = modelus(2, n);
    build_modinv();
    ll asub = 1, bsub = 1;
    ll num = n;
    for(int i = 1; i <= a; ++i, --num) {
        asub = ((asub % mod) * ((num * fact[i]) % mod))%mod;
    }
    num = n;
    for(int i = 1; i <= b; ++i, --num) {
        bsub = ((bsub % mod) * ((num * fact[i]) % mod))%mod;
    }
    ll ans = (ad % mod - (asub + bsub + 1)%mod + mod)%mod;
    cout << ans;
}
