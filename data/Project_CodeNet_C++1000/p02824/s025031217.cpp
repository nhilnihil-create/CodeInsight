
// Problem : B - Voting Judges
// Contest : AtCoder - AtCoder Grand Contest 041
// URL : https://atcoder.jp/contests/agc041/tasks/agc041_b
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

int n,m,v,p,a[100005];

bool check(int x){
    if(x<=p) return 1;
    if(a[x]+m < a[p]) return 0;
    int tot = 0;
    for(int i=1;i<=n;i++){
        if(i<p) tot += m;
        else if(i>=x) tot += m;
        else tot += a[x]+m-a[i];
    }
    if(tot < m*v) return 0;
    return 1;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>m>>v>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int lo = 1, hi = n, ans;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)) ans = mid, lo = mid+1;
        else hi = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
