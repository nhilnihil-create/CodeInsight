#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int my_ceil(int a, int b){
  return (a + b - 1) / b;
}

int main(){
  int H, A;
  cin >> H >> A;
  cout << my_ceil(H, A) << endl;
}
