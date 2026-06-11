
// Problem : D - Handstand 2
// Contest : AtCoder - AtCoder Beginner Contest 152
// URL : https://atcoder.jp/contests/abc152/tasks/abc152_d
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

vi digits(int x){
    vi ret;
    while(x){
        ret.pb(x%10);
        x /= 10;
    }
    reverse(all(ret));
    return ret;
}

void solve(){
    int n;
    cin>>n;
    vector<vi> cnt(10,vi(10));
    for(int i=1;i<=n;i++){
        vi v = digits(i);
        cnt[*v.begin()][*v.rbegin()]++;
    }
    int ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) ans += cnt[i][j]*cnt[j][i];
    }
    cout<<ans;
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