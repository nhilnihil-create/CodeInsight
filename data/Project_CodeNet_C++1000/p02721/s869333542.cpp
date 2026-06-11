#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll m = 998244353;

int main() {

    ll N, K, C;
    cin >> N >> K >> C;

    string S;
    cin >> S;

    vector<ll> L(2e5+9), R(2e5+9);
    ll d;
    ll i;
    d = 0;
    i = 0;
    while(i < K) {
        if (S[d] == 'x') {
            d++;
            continue;
        }
        else {
            L[i] = d;
            i++;
            d += (C+1);
        }
    }

    d = N-1;
    i = K-1;
    while(i >= 0) {
        if (S[d] == 'x') {
            d--;
            continue;
        }
        else {
            R[i] = d;
            i--;
            d -= (C+1);
        }
    }

    for (int i = 0; i < K; ++i) {
        if (L[i] == R[i]) cout << L[i] + 1 << endl;
    }

    return 0;
}
