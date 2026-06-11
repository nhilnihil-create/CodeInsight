#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int my_ceil(int a, int b){
  return (a + b - 1) / b;
}

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int x, y;
  x = my_ceil(A, D);
  y = my_ceil(C, B);
  if (x >= y) cout << "Yes" << endl;
  else cout << "No" << endl;
}
