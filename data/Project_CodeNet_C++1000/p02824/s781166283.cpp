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
    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    sort(ALL(a));
    int left = -1, right = n;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        int cnt = 0;
        ll nokori = (ll)(v - 1) * m;
        vector<int> vec;
        REP(i, n) {
            if (i == mid) continue;
            if (a[i] <= a[mid]) {
                nokori -= m;
            } else if (a[mid] + m < a[i]) {
                ++cnt;
                nokori -= m;
            } else {
                vec.push_back(a[i]);
            }
        }
        if (cnt >= p) {
            left = mid;
            continue;
        }
        reverse(ALL(vec));
        REP(i, SZ(vec)) {
            if (i < p - cnt - 1) nokori -= m;
            else nokori -= (a[mid] + m - vec[i]);
        }
        if (nokori > 0) left = mid;
        else right = mid;
    }
    
    cout << n - right << "\n";
    return 0;
}
