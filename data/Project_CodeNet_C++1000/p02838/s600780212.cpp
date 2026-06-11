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
#define mod 1000000007
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
int main() {
    ll n;
    cin >> n;
    vl a(n);
    for(auto &it: a) cin >> it;
    vector<vector<ll>> arr(n, vl(65));
    for(int j = 0; j <= 62; ++j) {
        if((1ll << j)&a[0]) {
            arr[0][j] = 1;
        }
    }
    for(int i = 1; i < n; ++i) {
        ll num = a[i];
        for(int j = 0; j <= 62; ++j) {
            if((1ll << j)&num) {
                arr[i][j] = arr[i - 1][j] +  1;
            }
            else {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    ll ans = 0;
    vl pow2(63);
    pow2[0] = 1;
    for(int i = 1; i <= 62; ++i) {
        pow2[i] = pow2[i - 1]*2 % mod;
    }
    for(int i = 1; i < n; ++i) {
        ll num = a[i];
        for(int j = 0; j <= 62; ++j) {
            if((1ll << j)&num) {
                ans = (ans%mod + ((i + 1 - arr[i][j])*pow2[j]%mod))%mod;
            }
            else {
                ans = (ans%mod + (arr[i][j]*pow2[j]%mod))%mod;
            }
        }
    }
    cout << ans;
}
