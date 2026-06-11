#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll ans=-1;
    for(ll i=0;i<100000;i++){
        if((ll)(i*1.08)==n){
            ans=i;
            break;
        }
    }
    if(ans==-1){
        cout << ":(" << endl;
    }
    else {
        cout << ans << endl;
    }
}
