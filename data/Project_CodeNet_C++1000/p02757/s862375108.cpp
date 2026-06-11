#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MAX_N = 100010;

int N, P;
string S;

int solve() {
    vector<int> cs(N); // S の累積和 % P
    reverse(S.begin(), S.end());

    // cs の作成
    int mul = 1;
    REP(i, N) {
        int num = S[i] - '0';
        if(i > 0) {
            cs[i] = cs[i-1] + ((mul * num) % P);
        }
        else {
            cs[i] = num;
        }
        cs[i] %= P;

        mul *= 10;
        mul %= P;
    }

    int ans = 0;
    // 今までに数 i が何回出てきたか
    vector<int> cnt(10010, 0);
    REP(i, N) {
        if(cs[i] == 0) { ans++; }
        ans += cnt[cs[i]];
        cnt[cs[i]]++;
    }
    return ans;
}

int corner() {
    // 2 か 5 なら 1 の位を見るだけでよい
    reverse(S.begin(), S.end());
    int ret = 0;
    REP(i, N) {
        int num = S[i] - '0';
        if(num % P == 0) {
            ret += N - i;
        }
    }
    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> P >> S;

    int ans = (P == 5 || P == 2) ? corner() : solve();
    printf("%lld\n", ans);

    return 0;
}

