#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int>a(n);
    vector<int>b(n);
    ll b2 =0, c2=0;
    vector<int>c(n);
    rep(i, 0, n)cin >> a[i];
    rep(i, 0, n){
        rep(j, i, n){
            if(a[i] > a[j])b2++;
        }
        rep(j, 0, i){
            if(a[j] < a[i])c2++;
        }
    }
    ll d = ((k+1)*k)/2;
    ll e = ((k-1)*k)/2;
    ll ans = ((b2*(d%mod))%mod+(c2*(e%mod))%mod)%mod;

    cout << ans << endl;
}