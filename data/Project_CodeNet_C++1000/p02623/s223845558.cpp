#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    vector<long long> b(m);
    rep(i, m) {
        cin >> b.at(i);
    }

    // cusum_a[i] + cusum_b[j] <= K となるように選ぶとき、i+jが取りうる最大値が答え

    // A, Bそれぞれの累積和を求めて引いたり足したりする
    // \sigma_{k = x}^{y} a[k]  = cusum_a[y + 1] - b[x] がO(1)
    vector<long long> cusum_a(n + 1, 0);
    vector<long long> cusum_b(m + 1, 0);

    rep(i, n) {
        cusum_a.at(i + 1) = cusum_a.at(i) + a.at(i);
    }

    rep(i, m) {
        cusum_b.at(i + 1) = cusum_b.at(i) + b.at(i);
    }

    // 最大読書数
    int ans_max = 0;

    // bの可能な最大読書数
    int num_b = m;

    // i=0から全探索し、それぞれについてj = Mから降順に操作する
    rep(i, n + 1) {
        // 差分
        long long diff = k - cusum_a.at(i);
        // aだけで読みきれなくなって差分がマイナスになったら終了
        if (diff < 0) {
            break;
        }

        // jを大きい方から走査する
        for (int j = num_b; j > -1; j--) {
            // 最初に差分内に収まればok
            if (cusum_b.at(j) <= diff) {
                // 最大数と比較
                ans_max = max(i + j, ans_max);
                // 次のループではこれより下を見ればよい
                num_b = j;
                break;
            }
        }
    }

    cout << ans_max << endl;
}
