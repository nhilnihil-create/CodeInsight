#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll X, N; cin >> X >> N;
    set<ll> ST; 
    for(int i = 0; i < N; i++) {
        ll a; cin >> a; ST.insert(a);
    }
    ll D = INF, ans = 1;
    for(int i = 0; i <= 101; i++){
        if(ST.find(i) != ST.end()) continue;
        ll d = abs(i - X);
        if(d < D){
            D = d;
            ans = i;
        }
    }
    cout << ans << endl;

}