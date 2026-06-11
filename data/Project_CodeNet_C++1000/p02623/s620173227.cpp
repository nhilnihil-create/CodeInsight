#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vi a(n), b(m), v(n+m);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < n; i++)v[i]=a[n-i-1];
    for(int i = 0; i < m; i++){
        cin>>b[i];
        v[n+i]=b[i];
    }
    int j = 0, s = 0, mx = 0;
    for(int i = 0; i < n+m; i++){
        s+=v[i];
        if(s>k)s-=v[j++];
        if(i>=n-1&&j<=n&&s<=k)mx=max(mx, i-j+1);
    }
    s=0, j = n+m-1;
    for(int i = n+m-1; i >= 0; i--){
        s+=v[i];
        if(s>k)s-=v[j--];
        if(i<=n&&j>=n-1&&s<=k)mx=max(mx, j-i+1);
    }
    cout<<mx;
}
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}