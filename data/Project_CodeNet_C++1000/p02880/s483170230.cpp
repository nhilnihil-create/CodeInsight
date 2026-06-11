#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  bool flag = false;

  rep2(i, 9) rep2(j, 9) if (n == i * j) flag = true;

  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl; 

  return 0;
}
