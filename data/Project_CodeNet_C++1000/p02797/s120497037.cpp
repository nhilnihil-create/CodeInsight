#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    rep(i, K) cout << S << " ";
    rep(i, N - K) {
        if (S != 1000000000) cout << S + 1 << " ";
        else cout << 1 << " ";
    }
    cout << endl;
    return 0;
}