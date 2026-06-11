#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    int r=n-2, l=1;
    int ans = a[n-1] - a[0];
    for(int i=1;i<n-1;i++) ans += abs(a[i]);
    cout<<ans<<endl;
    int plus=a[n-1], minus = a[0];
    vector <int> mi, pl;
    rep(i,n-2) if(a[i+1]<=0) mi.push_back(a[i+1]); else pl.push_back(a[i+1]);
    rep(i, mi.size()){
        cout<<plus<<' '<<mi[i]<<endl;
        plus -= mi[i];
    }
    rep(i,pl.size()){
        cout<<minus<<' '<<pl[i]<<endl;
        minus -= pl[i];
    }
    cout<<plus<<' '<<minus<<endl;
}
