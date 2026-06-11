#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  float N, D, a;
  cin >> N >> D;
  a = N / (D * 2 + 1);
  cout << ceil(a) << endl;
}