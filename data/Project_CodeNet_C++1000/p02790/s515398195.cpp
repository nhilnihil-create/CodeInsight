#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;


int main(){
  int a, b;
  cin >> a >> b;
  int c = min(a, b) + '0';
  int d = max(a, b);
  char S[d];
  rep(i, 10) S[i] = 0;
  rep(i, d) S[i] = c;
  cout << S << endl;
}
