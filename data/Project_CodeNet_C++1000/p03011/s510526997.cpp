#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int P=0, Q=0, R=0;

int main(){
  cin >> P >> Q >> R;
  cout << P + Q + R - max({P, Q, R}) << endl;
}