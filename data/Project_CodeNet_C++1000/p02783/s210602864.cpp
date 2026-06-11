#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll H, A;
  cin >> H >> A;


  ll ans;

  if(H%A==0)ans = H/A;
  else ans = H/A+1;

  cout << ans << endl;

  return 0;
}
