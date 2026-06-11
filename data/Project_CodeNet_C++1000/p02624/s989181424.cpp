#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll ll_mod=1e9+7;

int main(){
    ll n; cin >> n;
    ll ans=0;
    for(ll i=0; i<n; i++){
        ll im=i+1;
        ll k=n/im;
        ans += k*(k+1)*im/2;
    }
    cout << ans << "\n";
    return 0;
}