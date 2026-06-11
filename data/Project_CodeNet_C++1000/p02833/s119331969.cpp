#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n-1); i >= 0; --i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define snd second
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

double log5(double x) {
    return log(x) / log(5);
}

signed main() {
    int N;

    cin >> N;

    if (N < 2 || N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    // 圧倒的2の因数により、それは気にしなくていい
    // 5の因数の数を数えればよい。

    int digits = log5(N);
    int ans = 0;
    FORE(i, 1, digits) {
        // 5^i * 2, 5^i * 4, 5^i *6 ... maxは?
        int a = pow(5, i);
        int b = pow(5, i+1);

        // 5の奇数倍は除きたい…

        int num = (N / a) / 2 - (N / b) / 2;
        debug(i);
        debug(num);
        ans += num * i;
    }

    cout << ans << endl;
}
