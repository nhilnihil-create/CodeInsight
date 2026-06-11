#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    rep(i, N) cin >> W.at(i);

    int sum = 0;
    rep(i, N) {
        sum += W.at(i);
    }

    int S1 = 0, S2 = sum, minDiff = MOD;
    rep(t, N) { // T
        S1 += W.at(t);
        S2 -= W.at(t);
        minDiff = min(minDiff, abs(S2 - S1));
    }

    cout << minDiff << endl;

    return 0;
}
