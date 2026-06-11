#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M) % M;
}

int main() {
    ll N, K; cin >> N >> K;
    ll R = N - K;
    for (int i = 1; i <= K; i++){
        ll ans = 1;
        ll rb = i-1;
        ll rn = R-i+1;
        if(rb > R){
            cout << 0 << endl;
            continue;
        }
        
        ll k = K-1;
        for (int j = 1; j <= rb; j++){
            ans *= k;
            ans %= mod;
            k--;
        }
        for (int j = rb; j > 1; j--){
            ans *= RepeatSquaring(j, mod-2, mod);
            ans %= mod;
        }

        ll l = R+1;
        for (int j = 1; j <= i; j++){
            ans *= l;
            ans %= mod;
            l--;
        }
        for (int j = i; j > 1; j--){
            ans *= RepeatSquaring(j, mod-2, mod);
            ans %= mod;
        }

        cout << ans << endl;



    }

    return 0;
}