#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a);i<(b);++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+(b),(a).begin()+(c) // [b,c) イテレータ
#define INF 1000000000000000
#define MOD 1000000007
using PII = pair<int64_t, int64_t>;
using VI = vector<int64_t>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;
using i64 = int64_t;
template<typename T> void invec(vector<T> &A){for(T& a:A) cin >> a;}

void topsort(int v, const VVI &G, vector<bool> &seen, VI &order){
    seen[v] = true;
    for(int nv : G[v]){
        if (seen[nv]) continue;
        topsort(nv, G, seen, order);
    }
    order.push_back(v);
}

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int V, E; cin >> V >> E;
VVI G(V);
rep(_, 0, E){
    int s, t;  cin >> s >> t;
    G[s].push_back(t);
}

vector<bool> seen(V, 0);
VI order; // トポロジカルソート順。
rep(v, 0, V){
    if (seen[v]) continue;
    topsort(v, G, seen, order);
}
reverse(ALL(order));

for(int i: order) cout << i << "\n";

return 0;
}
// コンテスト前はtemplate振り返り。
// 書いて考える．場合分け．情報整理．
// 問題文から考える。自分ができることから考える。
// 単純に分かる量から．愚直解を実装して研究．
// 境界，出力文字列 チェック．行末にスペース入れない．
// 可読性優先．高速化次点．
// まずは全探索，分割，次にDP(小さい問題から大きな問題)
// 制限を見る．境界に注意．求めたい量の変域．動かせる量．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性→二分探索。逆から考える。
// 存在判定：構成方法，入力の特徴
// 構築問題。極端解を試す。
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 代数的処理．前処理によるクエリ高速化．
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// コーナーケース。境界値。数表出力プログラム作る
// 実行エラー：vector添え字超え．0割り．


