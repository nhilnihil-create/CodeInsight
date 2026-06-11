#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<ll> v(4);
    for(int i = 0; i < 4; i++) cin >> v[i];
    ll ans = -2e18;
    for(int i = 0; i < 2; i++){
        for(int j = 2; j < 4; j++){
            ans = max(ans, v[i] * v[j]);
        }
    }
    cout << ans << '\n';



    return 0;
}
