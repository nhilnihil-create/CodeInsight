#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n), ans(n,0);
    ll sum;
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n-1){
        ans[i+1] = a[i+1] - ans[i];
    }
    ans[0] = (a[0]-ans[n-1])/2;
    rep(i,0,n-1)ans[i+1] = a[i+1] - ans[i];
    cout << 2*ans[n-1] << " " ;
    rep(i,0,n-1)cout << 2*ans[i] << " " ;
    cout << endl;

}