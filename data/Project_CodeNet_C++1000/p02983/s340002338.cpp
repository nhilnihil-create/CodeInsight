
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int mod=2019;

int main(){
    ll l,r;
    cin >> l >> r;
    r = min(r,l+4038);
    ll ans=2018;
    for(ll i=l; i<=r; i++){
        for(ll j=i+1; j<=r; j++){
            ans = min(ans,(i*j)%2019);
        }       
    }
    cout << ans << endl;
}  