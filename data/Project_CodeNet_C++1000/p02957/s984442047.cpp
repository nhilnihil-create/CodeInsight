#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  if ((a - b) % 2 == 0) cout << (a + b) / 2 << endl;
  else cout << "IMPOSSIBLE" << endl;
}
