#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)




int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ac, ad, bc, bd;
  ac = a * c;
  ad = a * d;
  bc = b * c;
  bd = b * d;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  
  cout << max(bc ,max(bd, max(ac, ad))) << endl;

  return 0;
}
