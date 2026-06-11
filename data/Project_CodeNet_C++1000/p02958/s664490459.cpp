#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  // 入力を入れるvector
  vector<int> P(N);
  rep(i, N){
    cin >> P[i];
  }
  // 昇順の数列を入れるvector
  vector<int> Q(N);
  rep(i, N){
    Q[i] = i+1;
  }
  // PとRの要素が同じかどうかを判断するboolを入れるvector
  vector<bool> R(N);
  rep(i, N){
    if (P[i]!=Q[i]) R[i]=true;
    else R[i]=false;
  }
  // 異なっている箇所が2箇所以下であればOK
  int sums=0;
  rep(i, N){
    sums += R[i];
  }
  if (sums<=2) cout << "YES" << endl;
  else cout << "NO" << endl;
}