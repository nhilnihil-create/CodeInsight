#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  ll X;
  cin >> X;

  ll now = 100;
  for (int i = 1; ; i++){
    now += now / 100;
    if (now >= X){
      cout << i << endl;
      return 0;
    }
  }
}
