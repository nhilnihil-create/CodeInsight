#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  bool ok = false;
  if(n==m&&n!=l) ok = true;
  else if(n==l&&n!=m) ok = true;
  else if(m==l&&n!=m) ok = true;
  cout << (ok? "Yes" : "No") << endl;
}
