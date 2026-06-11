#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const long long MOD = 998244353;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll = long long;
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
#define RSORT(v) std::sort(v.rbegin(), v.rend())
constexpr auto PI = 3.14159265358979323846264338327950L;
int needleX[4] = { -1,0,1,0 };
int needleY[4] = { 0,1,0,-1 };


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pii> X;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        X.push_back(make_pair(x+y, x-y));
    }
    SORT(X);
    int ans = 0;
    int cur = -1000000000;
    for (int i = 0; i < N; ++i) {
        if (cur <= X[i].second) {
            ans++;
            cur = X[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
