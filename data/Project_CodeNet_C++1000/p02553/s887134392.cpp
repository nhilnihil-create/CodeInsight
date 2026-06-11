#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> x(2), y(2);
    cin >> x[0] >> x[1] >> y[0] >> y[1];
    if(x[0] <= 0 && x[1] >= 0) x.push_back(0);
    if(y[0] <= 0 && y[1] >= 0) y.push_back(0);
    ll ans = -1e18;
    for(ll a : x){
        for(ll b : y){
            ans = max(ans, a*b);
        }
    }
    cout << ans << endl;
    return 0;
}