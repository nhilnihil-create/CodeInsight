#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int main() { 
    ll N, N_10=10, N_9=9, N_8=8, mod=1000000007, ans;
    cin >> N;

    rep(i, N) {
        N_10 = (N_10 * 10) % mod;
        N_9  = (N_9  *  9) % mod;
        N_8  = (N_8  *  8) % mod;
    }

    ans = (N_10 - N_9 * 2 + N_8) % mod;
    ans = (ans+mod)%mod;
    cout <<  ans << "\n";
    return 0;
}
