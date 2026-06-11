#include <iostream>
#include <vector>
using namespace std;

// ダブリング
// ダブリングについては https://algo-logic.info/doubling/ を参照
class doubling {
   private:
    vector<vector<long long>> next;

   public:
    // コンストラクタ
    // ダブリングの前処理をする
    // maxk: 最大のK
    // next1: i番目の要素から1個先の要素のvector
    doubling(long long maxk, vector<long long> &next1) {
        // nextを初期化 リサイズしてnext[0]を初期化。
        const long long log2k = log2K(maxk);
        next.resize(log2k);
        next.front() = next1;
        const int n = next1.size();
        for (auto &&next_i : next) {
            next_i.resize(n);
        }

        // ダブリングの前処理
        for (int i = 0; i < log2k - 1; i++) {
            for (int j = 0; j < n; j++) {
                next[i + 1][j] = next[i][next[i][j]];
            }
        }
    }

    // ダブリングのクエリに答える
    // p番目の要素からk個先の要素を返す
    long long get(long long p, long long k) {
        const int log2k = log2K(k);
        for (int i = 0; i < log2k; i++) {
            if (k & (1LL << i)) p = next[i][p];
        }
        return p;
    }
    constexpr long long log2K(long long k) {
        int log2k = 1;
        while ((1LL << log2k) < k) log2k++;
        return log2k;
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 入力受け取り
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    // Aを0-basedに変換
    for (auto &&i : a) {
        i--;
    }

    // ダブリング前処理
    doubling d(k, a);
    // ダブリングクエリ
    const long long ans = d.get(0, k) + 1;

    cout << ans << "\n";
}
