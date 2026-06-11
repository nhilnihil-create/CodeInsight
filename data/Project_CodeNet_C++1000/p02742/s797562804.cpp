#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;




int main() {
  ll H, W;
  cin >> H >> W;
  

  if( H== 1 || W == 1){
    cout << 1 << endl;
  } else {
    cout << (H * W + 1) / 2 << endl;
  }


	return 0;
}

