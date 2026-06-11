// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define cps CLOCKS_PER_SEC
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
#define pr pair<int,int>
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { int operator()(int x) const { return x ^ RANDOM; }};
// cc_hash_table<int, int, hash<int>> cnt;

const int MAXN = 2005;
pair<int,int> x[MAXN];
int dp[MAXN][MAXN];
int n; 

int rec(int s,int e){
    if(s > e) return 0;
    int &ans = dp[s][e];
    if(ans != -1) return ans;

    int idx = s - 1 + n - (e - 1); 
    ans = max(rec(s+1,e) + abs(x[idx].s - s)*x[idx].f,rec(s,e-1) + abs(x[idx].s - e)*x[idx].f);

    return ans;
}

void solve(){

    cin>>n;
    FOR(i,1,n) {cin>>x[i].f; x[i].s = i;}
    
    sort(x+1,x+n+1); reverse(x+1,x+n+1);

    MINUS(dp);
    cout<<rec(1,n)<<endl;
}
 
signed main(){
 
    FastRead; 

    int t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}