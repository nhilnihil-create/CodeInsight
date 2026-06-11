#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

ll g(ll n) {
    return n*(n+1)/2;
}
int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ll j = N/i;
        ans += i*g(j); 
    }
    cout << ans << endl;
    return 0;
}
