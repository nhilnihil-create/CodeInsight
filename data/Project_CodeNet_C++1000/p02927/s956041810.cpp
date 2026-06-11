#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e14;
const ll mod = 1e9+7;
// __uint128_t



int main(){
    ll M, D; cin >> M >> D;
    ll ans = 0;
    vector<bool> Mem(105);
    for(int i = 10; i <= D; i++){
        if(i >= 10){
            ll d1 = i%10, d10 = i / 10;
            if(d10 >= 2 && d1 >= 2){
                ll m = d10*d1;
                if(m <= M) ans++;
            }
        }
    }
    cout << ans << endl;
}