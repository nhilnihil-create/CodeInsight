#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, D, cnt = 0; cin >> N >> D;
    for(int i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        if(a*a+b*b <= D*D) cnt++;
    }
    cout << cnt << endl;
}