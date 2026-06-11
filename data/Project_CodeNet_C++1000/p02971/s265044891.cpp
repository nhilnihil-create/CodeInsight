#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N){
    int a;
    cin >> a;
    A[i] = a;
  }
  // 最大値と二番目に大きい値を求めるためにvectorをコピー
  vector<int> B(N);
  B = A;
  // コピーしたものをソート
  sort(B.begin(), B.end());
  // 一番目に大きい値と二番目に大きい値
  int max_value1, max_value2;
  max_value1 = B[N-1];
  max_value2 = B[N-2];
  // もし二番目に大きい値が指定されれば最大値を出力する
  // もし最大値が指定されれば二番目に大きい値を出力する
  rep(i, N){
    if (A[i]!=max_value1) cout << max_value1 << endl;
    else cout << max_value2 << endl;
  }
}