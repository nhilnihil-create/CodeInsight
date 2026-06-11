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
    ll N;
    cin >> N;
    if (N & 1) {
        cout << 0 << "\n";
        return 0;
    }
    N /= 2;
    ll ans = 0;
    while (N) {
        ans += N / 5;
        N /= 5;
    }
    cout << ans << "\n";
    return 0;
}
