// 答えを見て実装
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int N;

    cin >> N;

    int ans = 0;
    int biggest_digit = 0;

    // 下から数えてnビット目の1が立っている個数
    // zeros[d]はn - ones[d]で求められる
    // zeros[d]は無いものを数える必要があるから、直接数えるのはちょっと難しい。
    // 最大の桁数を持って教えないと、スルーしてしまう

    vector<int> ones(64);
    REP(i, N) {
        int a;
        cin >> a;

        int digit = (int)log2(a) + 1;
        if (digit > biggest_digit) {
            biggest_digit = digit;
        }

        REP(d, digit) {
            int shift = (1LL << d);
            int flag = (a & shift);
            if (flag) {
                ones.at(d) += 1;
            }
        }
    }

    // bitごとに見て、0グループと1グループから1つずつ選んだものだけが生き残る
    // だから、各bitごとに、#{0の数} * #{1の数} を計算すればよい

    // 桁数
    FORE(d, 0, biggest_digit-1) {
        int c = ((N - ones.at(d)) * ones.at(d)) % MOD;
        REP(i, d) {
            c = (c * 2) % MOD;
        }
        ans = (ans + c) % MOD;
    }

    cout << ans << endl;
}
