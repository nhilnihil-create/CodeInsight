#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll h;
  cin >> h;
  ll cnt = 0;
  while(h != 0){
    h /= 2;
    cnt++;
  }
  ll ans = pow(2, cnt) -1;
  cout << ans << endl;
}
