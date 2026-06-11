
// Problem : E - Payment
// Contest : AtCoder - AtCoder Beginner Contest 155
// URL : https://atcoder.jp/contests/abc155/tasks/abc155_e
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
#define inf 1e12
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000005

//Solution

int dp[N][2];
string s;

int f(int i, int t){
    if(i == sz(s)) return 0;
    int &ret = dp[i][t];
    if(~ret) return ret;
    ret = inf;
    int x = s[i]-'0';
    if(t){
        if(i < sz(s)-1) x = 9-x;
        else x = 10-x;
        ret = min(ret,f(i+1,1)+x);
        ret = min(ret,f(i+1,0)+x+1);
    } else {
        ret = min(ret,f(i+1,0)+x);
        ret = min(ret,f(i+1,1)+x+1);
    }
    return ret;
}

void solve(){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    while(s.back() == '0') s.pop_back();
    s.insert(s.begin(),'0');
    cout<<f(0,0)<<endl;
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