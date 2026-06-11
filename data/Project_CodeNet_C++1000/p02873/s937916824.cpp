#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;
    int N = S.size() + 1;
    vector<ll> A(N, 0);
    rep(i, N - 1) if (S[i] == '<') A[i + 1] = A[i] + 1;
    rep(i, N - 1) if (S[N - 2 - i] == '>') A[N - 2 - i] =
        max(A[N - 2 - i], A[N - 1 - i] + 1);

    ll ans = 0;
    rep(i, N) ans += A[i];
    cout << ans << endl;
}
