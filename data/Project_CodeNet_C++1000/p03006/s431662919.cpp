#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define RANGE(a,b,c) (a).begin()+b,(a).begin()+c // コンテナ a の 要素 b から c へのイテレータ
#define MOD 1000000007
#define INF 1000000000
typedef pair<int64_t, int64_t> PII;
typedef vector<int64_t> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

map<PII, bool> seen;
void dfs(set<PII> &p, PII &pq, PII xy){
    seen[xy] = true;

    for(PII n: {make_pair(xy.first+pq.first, xy.second+pq.second), make_pair(xy.first-pq.first, xy.second-pq.second)})
        if (!seen[n] && p.count(n))
            dfs(p, pq, n);
}

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int N; cin >> N;
VI x(N), y(N); 
set<PII> p;
rep(i, 0, N) {
    cin >> x[i] >> y[i];
    p.insert(make_pair(x[i], y[i]));
}

if (N == 1){
    cout << "1\n";
    return 0;
}

int mini = INF;
rep(i, 0, N)
    rep(j, i+1, N){
        int cnt = 0;
        PII pq = make_pair(x[i] - x[j], y[i] - y[j]);
        seen.clear();
        for(PII xy: p)
            if (!seen[xy]){
                dfs(p, pq, xy);
                ++cnt;
            }
        mini = min(mini, cnt);
    }

cout << mini << "\n";
}

// 境界，出力文字列 チェック
// 可読性優先．高速化次点．
// まずは全探索，分割統治，次にDP
// 制限を見る．境界に注意．求めたい量の変域．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性，二分探索
// 存在判定：構成方法，入力の特徴
// gcd, lcm ,素因数分解．
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// テストケース作成は数表あり

