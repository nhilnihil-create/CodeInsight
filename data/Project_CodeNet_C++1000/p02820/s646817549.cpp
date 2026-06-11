
// Problem : D - Prediction and Restriction
// Contest : AtCoder - AtCoder Beginner Contest 149
// URL : https://atcoder.jp/contests/abc149/tasks/abc149_d
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

void solve(){
    int n,k;
    cin>>n>>k;
    int r,sc,p;
    cin>>r>>sc>>p;
    string s;
    cin>>s;
    map<char,int> m;
    m['r'] = p;
    m['s'] = r;
    m['p'] = sc;
    vi win(n);
    int ans = 0;
    for(int i=0;i<k;i++){
        for(int j=i;j<n;j+=k){
            if(j-k < 0 || !win[j-k] || s[j] != s[j-k]) {
                ans += m[s[j]];
                win[j] = 1;
            } else win[j] = 0;
        }
    }
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