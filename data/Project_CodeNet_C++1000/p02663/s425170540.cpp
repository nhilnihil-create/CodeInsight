#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int h1,m1,h2,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int d = m2-m1 + (h2-h1)*60;
  cout << d-k << endl;
}
