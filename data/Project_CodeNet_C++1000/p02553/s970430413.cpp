#include <bits/stdc++.h>

int main(){
  using namespace std;
  int64_t a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int64_t>res;
  res.push_back(a*c);
  res.push_back(b*d);
  res.push_back(a*d);
  res.push_back(b*c);
  
  cout << *max_element(res.begin(), res.end());
  return 0;
}