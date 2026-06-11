#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll a,b,c;
  cin >>a>>b >>c;
  ll d = c-a-b;
  if (d > 0 && 4*a*b < d*d) {
    cout << "Yes" << endl;
  }else cout << "No" << endl;
  return 0;
}