#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans;
  if(s == "Sunny") ans = "Cloudy";
  else if(s == "Cloudy") ans = "Rainy";
  else ans = "Sunny";
  cout << ans << endl;
  return 0;
}
