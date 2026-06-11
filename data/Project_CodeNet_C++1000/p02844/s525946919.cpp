
// Problem : D - Lucky PIN
// Contest : AtCoder - Sumitomo Mitsui Trust Bank Programming Contest 2019
// URL : https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
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
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    for(int a=0;a<=9;a++){
        for(int b=0;b<=9;b++){
            for(int c=0;c<=9;c++){
                int cnt = 0;
                for(char ch : s){
                    if(cnt == 0 && ch-'0' == a) cnt++;
                    else if(cnt == 1 && ch-'0' == b) cnt++;
                    else if(cnt == 2 && ch-'0' == c) cnt++;
                }
                if(cnt == 3) ans++;
            }
        }
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