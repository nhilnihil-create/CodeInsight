#include <bits/stdc++.h>
using namespace std;

//type
#define ll long long
typedef pair<int, int> P;
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素
#define Z class
// OTHER
// xの二乗を返す (関数テンプレート版)
template <typename T>
T square(T x) { return x * x; }
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))
// loop
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)

// vector
#define ALL(x) x.begin(), x.end()

// output
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define ln cout << '\n'
template <Z A>
void pr(A a)
{
  cout << a;
  ln;
}
template <Z A, Z B>
void pr(A a, B b)
{
  cout << a << ' ';
  pr(b);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

// d: 現在のケタ数
// val: 現在の値
// all: ここに格納していく (参照型にしておく)
void rec(int d, long long val, vector<long long> &all) {
    // 格納
    all.push_back(val);

    // 10 桁だったらそれ以上やらずに打ち切り
    if (d == 10) return;

    // 次の桁へ進む処理
    for (int j = -1; j <= 1; ++j) {
        int add = (val % 10) + j;
        if (add >= 0 && add<= 9) rec(d+1, val*10+add, all);
    }
}

int main() {
    int K;
    cin >> K;
    vector<long long> all;
    for (int v = 1; v < 10; ++v) rec(1, v, all);

    // 小さい順に並び替える
    sort(all.begin(), all.end());

    // K 番目
    cout << all[K-1] << endl;
}