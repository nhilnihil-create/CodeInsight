#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

constexpr int mod = 998244353;
int ModPow(int x, int y) {
    if (y == 0) return 1;
    long long a = ModPow(x, y / 2);
    if (y & 1) return a * a % mod * x % mod;
    else return a * a % mod;
}


int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, N) cin >> D[i];
    
    vector<int> cnt(N, 0);
    rep(i, N) ++cnt[D[i]];
    if (D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (cnt[0] == 0 != cnt[0] >= 2) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, N) {
        if (cnt[i] >= 1 && cnt[i - 1] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    long long ans = 1;
    REP(i, N) {
        if (cnt[i] == 0) break;
        ans *= ModPow(cnt[i - 1], cnt[i]);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
