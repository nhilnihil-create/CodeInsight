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

    int minDiff = MOD;
    rep(t, N) { // T
        int S1 = 0, S2 = 0;
        rep(i, N) {  // i loop
            if(i <= t) {
                S1 += W.at(i);
            } else {
                S2 += W.at(i);
            }
        }
        minDiff = min(minDiff, abs(S2 - S1));
    }

    cout << minDiff << endl;

    return 0;
}
