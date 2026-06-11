#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int x[5];
  rep(i,5) cin >> x[i];

  rep(i,5){
    if (x[i] == 0) {
      cout << i + 1 << endl;
      break;
    }
  }
}
