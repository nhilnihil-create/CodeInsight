
// Problem : B - Bingo
// Contest : AtCoder - AtCoder Beginner Contest 157
// URL : https://atcoder.jp/contests/abc157/tasks/abc157_b
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

int in[3][3], a[3][3], n;

bool bingo(){
    for(int i=0;i<3;i++){
        bool ok = true;
        for(int j=0;j<3;j++) ok &= (a[i][j] == 1);
        if(ok) return true;
    }
    for(int i=0;i<3;i++){
        bool ok = true;
        for(int j=0;j<3;j++) ok &= (a[j][i] == 1);
        if(ok) return true;
    }
    bool ok = true;
    for(int i=0;i<3;i++) ok &= (a[i][i] == 1);
    if(ok) return true;
    ok = true;
    for(int i=0;i<3;i++) ok &= (a[i][2-i] == 1);
    return ok;
}

void mark(int x){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(in[i][j] == x) a[i][j] = 1;
        }
    }
}

void solve(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cin>>in[i][j];
    }
    cin>>n;
    while(n--){
        int x; cin>>x;
        mark(x);
    }
    if(bingo()) cout<<"Yes\n";
    else cout<<"No\n";
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