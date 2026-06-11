#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;

  if(k == 1) puts("0");
  else cout << (n-k) << endl;
}