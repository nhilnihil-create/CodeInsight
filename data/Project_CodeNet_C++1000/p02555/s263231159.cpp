#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    ll S;
    cin >> S;
    ll d[S+1], mod = 1000000007;
    d[0] = 1;
    for (int i = 1; i <= S; ++i) {
        d[i] = 0;
        for (int j = 0; j <= i-3; ++j) {
            d[i] += d[j];
            d[i] %= mod;
        }
    }

    cout << d[S] % mod << "\n";
    return 0;
}