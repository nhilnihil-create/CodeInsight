#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, d;
  cin >> N;
  vector<int> X(N);
  rep(i, N){
    cin >> d;
    X[i] = d;
  }
  sort(X.begin(), X.end());
  cout << X[N/2] - X[N/2-1] << endl;
}