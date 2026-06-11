
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  string S, T;
  int A, B;
  string U;
  cin >> S >> T >> A >> B >> U;
  map<string, int> D;
  D[S] = A;
  D[T] = B;
  D[U] --;
  cout << D[S] << " " << D[T] << endl;
}
