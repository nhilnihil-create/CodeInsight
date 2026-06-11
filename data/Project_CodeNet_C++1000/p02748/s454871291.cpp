
// Problem : B - Nice Shopping
// Contest : AtCoder - Social Infrastructure Information Systems Division, Hitachi Programming Contest 2020
// URL : https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

void solve(){
    int A,B,C;
    cin>>A>>B>>C;
    vi a(A+1), b(B+1);
    int mna = inf, mnb = inf, mn;
    for(int i=1;i<=A;i++) cin>>a[i], mna = min(mna, a[i]);
    for(int i=1;i<=B;i++) cin>>b[i], mnb = min(mnb, b[i]);
    mn = mna + mnb;
    for(int i=0;i<C;i++){
        int x,y,c;
        cin>>x>>y>>c;
        mn = min(mn, a[x]+b[y]-c);
    }
    cout<<mn<<endl;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}