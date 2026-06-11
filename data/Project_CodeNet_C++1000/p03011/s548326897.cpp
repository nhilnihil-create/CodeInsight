#include <bits/stdc++.h>
using namespace std;

int main(){
  int p, q, r;
  cin >> p >> q >> r;
  
  vector<int> ans(3);
  ans.at(0) = p;
  ans.at(1) = q;
  ans.at(2) = r;
  sort(ans.begin(), ans.end());
  
  cout << ans.at(0) + ans.at(1) << endl;
}