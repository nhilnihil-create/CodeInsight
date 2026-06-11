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
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> S(N);
    rep(i, N) {
        char c;
        cin >> c;
        S[i] = c - '0';
    }
    if (P == 2 || P == 5) {
        lint ans = 0;
        rep(i, N) {
            if (S[i] % P == 0) ans += (i + 1);
        }
        cout << ans << "\n";
        return 0;
    }
    reverse(S.begin(), S.end());
    vector<int> T(N);
    int d = 1;
    rep(i, N) {
        T[i] = S[i] * d % P;
        d = d * 10 % P;
    }
    map<int, int> mp;
    lint ans = 0;
    int sum = 0;
    ++mp[sum];
    rep(i, N) {
        sum = (sum + T[i]) % P;
        ans += mp[sum];
        ++mp[sum];
    }
    cout << ans << "\n";
    return 0;
}
