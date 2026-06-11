#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  long double L;
  cin >> L;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  long double E = L / 3.0;
  long double ans = E*E*E;

  
  cout << setprecision(18) << ans << endl;

  return 0;
}
