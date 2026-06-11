#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int K;
    cin >> K;
    string S;
    cin >> S;
    K = min(K, sz(S));
    rep(i, K) cout << S[i];
    if (sz(S) > K) puts("...");
    return 0;
    // ll, 0, -, 1i, for s&g
}