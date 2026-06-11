#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define uint unsigned int
#define ull  unsigned long long
#define pb push_back
#define mk make_pair
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define X first
#define Y second
#define umap unordered_map
#define speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setvalue(d,s,e,n) for(int qwe = s; qwe < e; ++qwe) d[qwe] = n
#define mset multiset
#define pqueue priority_queue
   
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
        
const int  N = 3e3 + 314;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 998244353;
const double eps = 1e-9;
const long long LINF = 1e18 + 3141;
ll dp[N][N];
int a[N];
int n, s;
ll bp(ll a, ll n){
    a %= MOD; 
    ll ans = 1;
    while(n) {
        if(n & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}
void solve(){
    cin >> n >> s;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[0][0] = bp(2, n);

    ll inv2 = bp(2, MOD - 2);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= s; ++j)
            dp[i][j] = dp[i - 1][j];
        for(int j = s; j >= a[i]; --j) {
            dp[i][j] += (dp[i - 1][j - a[i]] * inv2);
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][s];
}
 
int main(){
    speed();
    int t = 1;

    // cin >> t;
    while(t--)solve();
}