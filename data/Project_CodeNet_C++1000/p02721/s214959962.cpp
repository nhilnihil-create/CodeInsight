#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S; cin >> S;
    auto solve = [&]() {
        vector<int> W(N);
        int n = 0, t = 1;
        rep(i, N) {
            if(n == 0 && S[i] == 'o') W[i] = t++, n = C;
            else if(n) n--;
            if(t == K + 1) break;
        }
        return W;
    };
    auto L = solve();
    reverse(S.begin(), S.end());
    auto R = solve();
    reverse(R.begin(), R.end());
    rep(i, N) {
        if(L[i] == K - R[i] + 1 && L[i]) cout << i + 1 << '\n';
    }
    return 0;
}
