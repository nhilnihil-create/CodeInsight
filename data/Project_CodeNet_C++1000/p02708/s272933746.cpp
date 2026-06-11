#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll MOD = 1000000007;
ll total(ll n, ll r) {
    return ((r-n+1) * (n + r)) / 2; 
}

int main (void){
    
    int N, K;
    cin >> N >> K;
    
    ll ans = 0;
    for (int i = K; i <= N+1; i++) {
        ll min = total(0, i-1)%MOD;
        ll max = total(N-i+1, N)%MOD;
        ans += (max - min + 1)%MOD;
        if (ans < 0) ans += MOD;
    }
    
    cout << (ans)%MOD << endl;
}
