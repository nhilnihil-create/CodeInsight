#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= 2000; i++) {
    if ((i*8)/100 == a && (i*10)/100 == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}