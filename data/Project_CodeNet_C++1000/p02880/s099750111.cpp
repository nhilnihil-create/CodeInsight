#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力部(N)
  int N;
  cin >> N;

  // 条件を満たすパターンの数をカウントする変数
  int cnt = 0;

  // 1~9までのループを行う。
  for(int i = 1; i < 10; i++) {

    // iでちょうど割り切れて、Nをiで割ったあまりが9以下の時、
    // この i と N/iの演算結果 に積は N になり、
    // Nをiで割ったあまりなので問題文の条件を満たす。
    if(N % i == 0 && N / i < 10) {

      //cnt(条件を満たすパターンの数をカウントする変数) に1を加算
      cnt++;

    }
  }

  if(cnt) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
