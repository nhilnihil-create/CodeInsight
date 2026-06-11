#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int h, a;
  cin >> h >> a;

  int ans = ceil(double(h) / a);
  cout << ans << endl;
}
