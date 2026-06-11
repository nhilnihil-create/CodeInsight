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
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;

int main() {
    int N, K;
    cin >> N >> K;
    if (K > (N - 1) * (N - 2) / 2) {
        cout << -1 << "\n";
        return 0;
    }
    vector<pair<int, int>> ans;
    REP(i, N) ans.push_back(pair<int, int>{0, i});
    int X = (N - 1) * (N - 2) / 2 - K;
    int a = 1, b = 2;
    while (X) {
        ans.push_back(pair<int, int>{a, b});
        ++b;
        if (b >= N) {
            ++a;
            b = a + 1;
        }
        --X;
    }
    cout << SZ(ans) << "\n";
    rep(i, SZ(ans)) cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    return 0;
}
