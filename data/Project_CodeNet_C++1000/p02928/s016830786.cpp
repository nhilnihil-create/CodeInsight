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
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    const int mod = 1000000007;
    
    lint N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    lint cnt = 0, X = 0;
    rep(i, N) rep(j, N) {
        if (i < j && a[i] > a[j]) ++cnt;
        if (a[i] > a[j]) ++X;
    }
    cout << (cnt * K % mod + (K - 1) * K / 2 % mod * X % mod) % mod << "\n";
    return 0;
}
