#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void solve() {
    int N, K, S;
    cin >> N >> K >> S;
    int n = S;
    int m = S + 1;
    if(n == 1e9) m = S - 1;
    rep(i, K) cout << n << " ";
    for(int i = K; i < N; ++i) cout << m << " ";
    cout << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
