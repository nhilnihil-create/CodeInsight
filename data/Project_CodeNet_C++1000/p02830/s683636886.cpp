#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  string U;
  rep(i, N){
    U += S[i];
    U += T[i];
  }
  cout << U << endl;
}
