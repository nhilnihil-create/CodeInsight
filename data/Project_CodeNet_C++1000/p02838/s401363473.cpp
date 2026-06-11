#include <bits/stdc++.h>

using namespace std;

static const int mod = 1000000007;

int main (void) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A.at(i);
    }

    long long ans = 0;
    for ( int i = 0; i < 60; i++ ) {
        long long n_one = 0;
        for ( int j = 0; j < N; j++ ) {
            if ( (A.at(j) >> i) & 1 ) {
                n_one++;
            }
        }
        long long now = (n_one * (N - n_one)) % mod;
        for ( int j = 0; j < i; j++ ) {
            now = (now * 2) % mod;
        }
        ans += now;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
