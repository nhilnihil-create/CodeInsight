#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<long long> ans(0);
  ans.push_back(a * c);
  ans.push_back(b * c);
  ans.push_back(d * a);
  ans.push_back(b * d);
  
  sort(ans.begin(), ans.end());
  cout << ans[3] << endl;
}
