#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  int ans2;
  if(w/2 == x && h/2 == y) ans2 = 1;
  else ans2 = 0;
  double area = w*h/2;
  printf("%.10f\n", area);
  cout << ans2 << endl;
}
