#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for(auto &x:a) {
        cin >> x;
        if(x == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(auto x:a){
        if(x > static_cast<ll>(1e+18) / ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= x;
    }
    cout << ans << endl;
}
