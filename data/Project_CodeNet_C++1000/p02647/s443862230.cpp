
// Problem : C - Lamps
// Contest : AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2020
// URL : https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
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
#define N 200005

int n,k;
vi a;

void operation(){
    vi res(n);
    for(int i=0;i<n;i++){
        int l = max(0LL,i-a[i]);
        int r = min(n-1,i+a[i]);
        res[l]++;
        if(r+1 < n) res[r+1]--;
    }
    for(int i=1;i<n;i++) res[i] += res[i-1];
    a = res;
}

bool is_done(){
    int ret = true;
    for(int i=0;i<n;i++) ret &= (a[i] == n);
    return ret;
}

void solve(){
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--){
        operation();
        if(is_done()) break;
    }
    for(int i : a) cout<<i<<" ";
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