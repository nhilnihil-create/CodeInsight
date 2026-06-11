#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void solve() {
    int64_t A, B, N;
    cin >> A >> B >> N;
    auto f = [&](int64_t x) { return A * x / B - A * (x / B); };
    if(B - 1 <= N) cout << f(B - 1) << '\n';
    else cout << f(N) << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
