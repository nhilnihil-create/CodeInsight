#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 998244353;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  ll a, v, b, w, t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;

  if(w >= v) {
    cout << "NO" << endl;
    return 0;
  } else {
    if ((double)abs(a-b) / (double)(v-w) <= t) {
      cout << "YES" << endl;
      return 0;
    } else { 
      cout << "NO" << endl;
      return 0;
    }
  } 
    return 0;
}
