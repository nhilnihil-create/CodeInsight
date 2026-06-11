#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

char S[10];

int main(){
  int a, b;
  cin >> a >> b;
  int c = min(a, b) + '0';
  int d = max(a, b);
  rep(i, d) S[i] = c;
  cout << S << endl;
}
