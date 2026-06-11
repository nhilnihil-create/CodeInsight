#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int N;

    cin >> N;

    vector<int> As(N);
    REP(i, N) {
        cin >> As.at(i);
    }

    int ans = 0;
    for (auto a : As) {
        ans = ans ^ a;
    }

    if (ans == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
