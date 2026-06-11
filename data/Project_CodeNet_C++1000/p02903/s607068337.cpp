#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w, a, b; cin >> h >> w >> a >> b;

  rep(i, h) {
    rep(j, w) {
      if((i<b)^(j<a)) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
}
      
