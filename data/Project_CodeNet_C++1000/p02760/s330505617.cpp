//コンパイラ最適化用
#pragma GCC optimize("Ofast")

//インクルード(アルファベット順)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//INT_MAXなど
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
  int N;
  vector<vector<int> > A(3, vector<int>(3));
  vector<vector<bool> > BINGO(3, vector<bool>(3));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cin >> A[i][j];
      BINGO[i][j] = false;
    }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;

    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        if (A[j][k] == input) {
          BINGO[j][k] = true;
          break;
        }
      }
  }

  for (int i = 0; i < 3; i++)
    if (BINGO[i][0] && BINGO[i][1] && BINGO[i][2]) {
      cout << "Yes" << endl; return 0;
    }

  for (int j = 0; j < 3; j++)
    if (BINGO[0][j] && BINGO[1][j] && BINGO[2][j]) {
      cout << "Yes" << endl; return 0;
    }

  if ((BINGO[0][0] && BINGO[1][1] && BINGO[2][2]) || 
      (BINGO[0][2] && BINGO[1][1] && BINGO[2][0])) {
        cout << "Yes" << endl; return 0;
      }

  cout << "No" << endl;

  return 0;
}