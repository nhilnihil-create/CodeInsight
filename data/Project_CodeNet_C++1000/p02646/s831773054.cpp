#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  int a, va, b, vb, t;
  cin >> a >> va >> b >> vb >> t;
  if(a == b){
    cout << "YES";
    return 0;
  }
  if(va <= vb){
    cout << "NO";
    return 0;
  }
  function<int(int, int)>Ceil = [&](int x, int y)
  {
    if(x % y == 0) return x / y;
    return x / y + 1;
  };
  int need;
  if(b > a) need = Ceil(b - a, va - vb);
  else need = Ceil(a - b, va - vb);
  if(need > t){
    cout << "NO";
  }
  else{
    cout << "YES";
  }
}
