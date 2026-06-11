
// Problem : D - Semi Common Multiple
// Contest : AtCoder - AtCoder Beginner Contest 150
// URL : https://atcoder.jp/contests/abc150/tasks/abc150_d
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
    int n,m;
    cin>>n>>m;
    vi a(n);
    int cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2){
            cout<<0<<endl;
            return;
        }
        a[i] /= 2;
        int cur = 0, tmp = a[i];
        while(tmp%2 == 0) tmp /= 2, cur++;
        if(!i) cnt = cur;
        else if(cur != cnt){
            cout<<0<<endl;
            return;
        } 
    }
    int ans = a[0];
    for(int i=1;i<n;i++){
        ans = (ans*a[i])/__gcd(ans,a[i]);
        if(ans > m){
            cout<<0<<endl;
            return;
        }
    }
    int res = m/ans;
    res = (res+1)/2;
    cout<<res;
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