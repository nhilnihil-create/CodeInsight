#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int my_ceil(int a, int b){
  return (a + b - 1) / b;
}

int main(){
  int N;
  cin >> N;
  cout << fixed << setprecision(10);
  cout << (double) my_ceil(N, 2) / (double) N << endl;
}