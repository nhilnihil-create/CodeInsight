#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;

  rep(i, S.size()){
    // 出力する文字が'A'からどれだけ進ませるか
    int gap = S[i] - 'A' + N;
    // Zの次はAにするために26で割ったあまりを利用する
    cout << (char) ('A' + (gap % 26));
  }
  cout << endl;
}
