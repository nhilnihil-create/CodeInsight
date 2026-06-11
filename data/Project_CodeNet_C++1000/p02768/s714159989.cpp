
// Problem : D - Bouquet
// Contest : AtCoder - AtCoder Beginner Contest 156
// URL : https://atcoder.jp/contests/abc156/tasks/abc156_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Macros

#define ll long long
#define db long double
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define inf 1e10
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 100005

//Solution

int binpow(int x,int y){
    x %= mod;
    int res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y = y/2;
    }
    return res;
}
 
int inv(int a){
    return binpow(a,mod-2);
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans = binpow(2,n)-1;
    ans += mod;
    ans %= mod;
    int cur = 1;
    for(int i=0;i<a;i++){
        cur *= n-i;
        cur %= mod;
        cur *= inv(a-i);
        cur %= mod;
    }
    ans -= cur;
    ans += mod;
    ans %= mod;
    cur = 1;
    for(int i=0;i<b;i++){
        cur *= n-i;
        cur %= mod;
        cur *= inv(b-i);
        cur %= mod;
    }
    ans -= cur;
    ans += mod;
    ans %= mod;
    cout<<ans<<endl;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tests;
    //cin>>tests;
    tests = 1;
    while(tests--){
        solve();
    }
    return 0;
}