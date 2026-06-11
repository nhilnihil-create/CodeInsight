#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll D=60;
const ll MAX_N=200005;
int main() {
    ll n,k;
    cin >> n >> k;
    ll to[D][MAX_N];
    for(ll i=0;i<n;i++){
        cin >> to[0][i];
        to[0][i]--;
    }
    for(ll i=0;i<D-1;i++){
        for(ll j=0;j<n;j++){
            to[i+1][j]=to[i][to[i][j]];
        }
    }
    ll v=0;
    for(ll i=D-1;i>=0;i--){
        ll l = 1ll<<i;
        if(l<=k){
            v=to[i][v];
            k-=l;
        }
    }
    cout << v+1 << endl;
}
