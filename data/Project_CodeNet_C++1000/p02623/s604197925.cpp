#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    ll b[m];
    rep(i,m){
        cin >> b[i];
    }
    ll ans = 0;
    ll tot = 0;
    rep(i,m) tot += b[i];
    ll j = m;
    for(int i=0; i<=n; i++){
        while(j>0 && tot > k){
            j--;
            tot -= b[j];
        }
        if(tot>k) break;
        ans = max(ans, i+j);
        if(i==n) break;
        tot += a[i];
    }
    cout << ans << endl;
}
