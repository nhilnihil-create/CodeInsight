#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> schL(1, -1);  // 仕事を前に詰めたときの仕事日
    vector<int> schR(1, N);   // 仕事を後ろに 〃

    for (int i = 0; i < N; ++i) {
        if ((int)schL.size() == K + 1) break;
        if (S[i] == 'o') {
            schL.push_back(i);
            i += C;
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        if ((int)schR.size() == K + 1) break;
        if (S[i] == 'o') {
            schR.push_back(i);
            i -= C;
        }
    }

    vector<int> flag(N + 1, 0);  // flag[i] > 0 -> 働かなくても良い日

    for (int i = 0; i <= K; ++i) {
        int l = i, r = K - i;
        flag[schL[l] + 1]++;
        flag[schR[r]]--;
    }
    for (int i = 1; i < N; ++i) { flag[i] += flag[i - 1]; }

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'o' && flag[i] == 0) cout << i + 1 << endl;
    }

    return 0;
}