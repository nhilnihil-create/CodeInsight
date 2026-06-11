#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll K; cin >> K;
    if(K % 7 == 0) K /= 7;
    if(K % 2 == 0 || K % 5 == 0){ cout << -1 << endl; return 0;}
    ll cnt = 1;
    ll X = 1;
    while(1){
        if(X % K == 0){ cout << cnt << endl; return 0;}
        X *= 10;
        X++;
        X %= K;
        cnt++;
    }
}