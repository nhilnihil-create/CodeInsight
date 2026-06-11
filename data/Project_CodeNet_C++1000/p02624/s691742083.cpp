#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

ll sigma(ll N){
    return (N*(N+1))/2;
}

int main(){
    ll N; cin >> N;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ll num = N / i;
        ans += sigma(num)*i;
    }
    cout << ans << endl;
}