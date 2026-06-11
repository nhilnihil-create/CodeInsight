#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

char S[4];

int main(){
  // 配列に格納
  rep(i, 4){
    cin >> S[i];
  }
  // 並び替えてから条件判定
  sort(S, S+4);
  if (S[0]==S[1] && S[1]!=S[2] && S[2]==S[3]) cout << "Yes" << endl;
  // 出力
  else cout << "No" << endl;
}