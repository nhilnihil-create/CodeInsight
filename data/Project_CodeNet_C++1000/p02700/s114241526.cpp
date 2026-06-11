#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int x = (a + d - 1) / d;  //高橋君のモンスターの体力が0以下になる回数
  int y = (c + b - 1) / b;
  if (x >= y) cout << "Yes" << endl;
  else cout << "No" << endl;
}
