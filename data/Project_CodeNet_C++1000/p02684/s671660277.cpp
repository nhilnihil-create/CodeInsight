#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

/*
ダブリングは、全体の要素数がN個あって1回移動した時に
どの要素に到達するのか定まっているとき、
「K個先の要素を求めるのに 𝑂(𝐾) かかる」ような状況において

- 前処理：𝑂(𝑁log𝐾) 時間, 𝑂(𝑁log𝐾) 空間
- クエリ：𝑂(log𝐾)

で行うことができるようにするアルゴリズムです

前処理：「doubling[k][i] : 𝑖 番目の要素から 2𝑘 先の要素は何か」を以下の式を利用して計算
doubling[k+1][i] = doubling[k][doubling[k][i]]

クエリ：前処理した結果を利用して K 個先の要素を求める
現在地を now として、𝐾 を2進数として見た時の全ての桁について以下を行う
𝐾 の 𝑘 桁目 が 1 ならば now = doubling[k][now] とする
*/

int main() {
    long long N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        A.at(i)--;  // 0-indexed に変更
    }

    int d = 1;
    // Kより大きいbit列を作る(2^d > Kとなるようなdを見つけている)
    while ((1LL << d) < K) d++;

    // doubling[k][i] : i番目から 2^k 進んだ町
    vector<vector<int> > doubling(d, vector<int>(N));

    // i番目から1進んだ町
    for (int i = 0; i < N; i++) {
        doubling.at(0).at(i) = A.at(i);
    }

    // 前処理 doubling の計算
    // doubling[d][0〜n-1]を求める
    // 町iから2^k個先の町がどこかという情報をもつdpテーブルを作成
    for (int k = 0; k < d - 1; k++) {
        for (int i = 0; i < N; i++) {
            doubling.at(k + 1).at(i) = doubling.at(k).at(doubling.at(k).at(i));
        }
    }

    // 現在の町
    int now = 0;
    // Kの桁を1桁目を見ていく
    for (int k = 0; K > 0; k++) {
        // Kのk桁目に1が立っているならば、now = doubling[k][now]と更新する
        if (K & 1) now = doubling.at(k).at(now);
        // Kの1桁目を消去
        K = K >> 1;
    }
    cout << now + 1 << endl;
}
