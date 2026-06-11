#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int64_t h, w;
  cin >> h >> w;
  if(min(h, w) == 1) cout << 1;
  else cout << ( h * w + 1) / 2;
  return 0;
}
