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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    vector<int> sum(n + 1, 0);
    REP(i, n) sum[i + 1] = (sum[i] + a[i]) % k;
    map<int, int> mp;
    ll ans = 0;
    REP(i, n + 1) {
        if (i >= k) {
            --mp[((sum[i - k] - (i - k)) % k + k) % k];
        }
        ans += mp[((sum[i] - i) % k + k) % k];
        ++mp[((sum[i] - i) % k + k) % k];
    }
    
    cout << ans << "\n";
    return 0;
}
