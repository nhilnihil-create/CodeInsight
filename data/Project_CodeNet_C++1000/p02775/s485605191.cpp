#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string S;
    cin >> S;
    vector<int> dp1(SZ(S), 0), dp2(SZ(S), 0);
    dp1[SZ(S) - 1] = S[SZ(S) - 1] - '0';
    dp2[SZ(S) - 1] = 10 - (S[SZ(S) - 1] - '0');
    for (int i = SZ(S) - 2; i >= 0; --i) {
        int n = S[i] - '0';
        dp1[i] = min(n + dp1[i + 1], n + 1 + dp2[i + 1]);
        dp2[i] = min(10 - n + dp1[i + 1], 9 - n + dp2[i + 1]);
    }
    cout << min(dp1[0], dp2[0] + 1) << "\n";
    return 0;
}
