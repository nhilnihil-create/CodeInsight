#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, K;
string S;

void solve() {
    cin >> N >> K >> S;

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        ans += S[i] == S[i+1];
    }
    cout << min(ans + 2 * K, N - 1) << endl;
}

int main() {
    solve();
    return 0;
}

