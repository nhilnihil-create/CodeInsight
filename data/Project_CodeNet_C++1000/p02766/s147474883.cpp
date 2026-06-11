#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

class Radix {
   private:
    const char* s;
    int a[128];

   public:
    Radix(const char* s = "0123456789ABCDEF") : s(s) {
        int i;
        for (i = 0; s[i]; ++i) a[(int)s[i]] = i;
    }
    std::string to(long long p, int q) {
        int i;
        if (!p) return "0";
        char t[64] = {};
        for (i = 62; p; --i) {
            t[i] = s[p % q];
            p /= q;
        }
        return std::string(t + i + 1);
    }
    std::string to(const std::string& t, int p, int q) {
        return to(to(t, p), q);
    }
    long long to(const std::string& t, int p) {
        int i;
        long long sm = a[(int)t[0]];
        for (i = 1; i < (int)t.length(); ++i) sm = sm * p + a[(int)t[i]];
        return sm;
    }
};

int main() {
    INIT;

    ll N, K;
    cin >> N >> K;

    Radix r;
    cout << SZ(r.to(N, K)) << endl;

    return 0;
}