#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  ll X;
  cin >> X;
  int ans = 0;
  ll yokin = 100;
  while (yokin < X){
    yokin += yokin / 100;
    // 以下ではダメ
    // yokin += (ll) (yokin * 0.01);
    ans ++;
  }
  cout << ans << endl;
}
