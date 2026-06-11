
// Problem : D - Knight
// Contest : AtCoder - AtCoder Beginner Contest 145
// URL : https://atcoder.jp/contests/abc145/tasks/abc145_d
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
#define N 2000005

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
 
int fact[N], invfact[N];
 
void precompute(){
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%mod;
    invfact[N-1] = inv(fact[N-1])%mod;
    for(int i=N-2;i>=0;i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
}
 
int ncr(int n, int r){
    if(n<r) return 0;
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}

void solve(){
    precompute();
    int x,y;
    cin>>x>>y;
    if((x+y)%3){
        cout<<0<<endl;
        return;
    }
    int n = (2*y-x)/3;
    int m = (2*x-y)/3;
    if(n < 0 || m < 0){
        cout<<0<<endl;
        return;
    }
    cout<<ncr(m+n,n)<<endl;
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