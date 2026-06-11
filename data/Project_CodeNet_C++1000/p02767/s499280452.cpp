//コンパイラ最適化用
#pragma GCC optimize("Ofast")

//インクルード(アルファベット順)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>
#include<chrono>//実行時間計測
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm,accumulate
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//順序保持しないmap
#include<unordered_set>//順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

// clang++ main.cc -std=c++11 -stdlib=libc++

/*
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
*/

signed main(){
  int res = INT_MAX;
  int N;
  cin >> N;

  vector<int> X(N);
  for (int i = 0; i < N; i ++)
    cin >> X[i];

  for (int p = 1; p <= 100; p++) {
    int hp = 0;
    for (int j = 0; j < N; j++) {
      hp += (X[j] - p) * (X[j] - p);
    }
    res = min(res, hp);
  }
  cout << res << endl;

  return 0;
}