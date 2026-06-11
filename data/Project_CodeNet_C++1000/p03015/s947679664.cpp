#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    string L; cin >> L;
    int n = L.length();
    vector<vector<ll> > memo(n, vector<ll>(2));
    memo[0][0] = 1;
    memo[0][1] = 2;
    for (int i = 1; i < L.length(); i++) {
        if (L[i] == '1') {
            memo[i][0] = (memo[i-1][0] * 3 + memo[i-1][1]) % MOD;
            memo[i][1] = (memo[i-1][1] * 2) % MOD;
        } else {
            memo[i][0] = (memo[i-1][0] * 3) % MOD;
            memo[i][1] = memo[i-1][1];
        }
    }
    cout << (memo[n-1][0] + memo[n-1][1]) % MOD << endl;
}
