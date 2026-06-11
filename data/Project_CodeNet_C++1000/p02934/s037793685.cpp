#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;

int main(){ 
  Int N;
  cin >> N;
  vector<Int> A(N);
  rep(i,N) cin >> A[i];
  
  vector<double> AI(N);
  rep(i,N) {
    AI[i] = 1.0 / (double)A[i];
  }
  
  double x = 0;
  rep(i,N) x += AI[i];
  
  x = 1.0 / x;
  
  cout << setprecision(10);
  cout << x << endl;

}