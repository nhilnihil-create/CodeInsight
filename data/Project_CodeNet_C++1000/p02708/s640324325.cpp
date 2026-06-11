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
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    lrep(i, k, n+2){
        ans += (((((n)+(n-i+1))%mod)* (i%mod)/2 - ((i-1)%mod)*(i%mod)/2)+1)%mod;
        //cout << ans << endl;
    }
    cout << ans%mod << endl;
}