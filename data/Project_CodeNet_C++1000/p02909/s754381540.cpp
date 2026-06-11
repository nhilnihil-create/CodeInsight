#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s, ans;
  cin >> s;
  if(s == "Sunny") ans = "Cloudy";
  if(s == "Cloudy") ans = "Rainy";
  if(s == "Rainy") ans = "Sunny";
  cout << ans << endl;
}