#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s, t;
  cin >> s;
  if(s=="Sunny") t="Cloudy";
  if(s=="Cloudy") t="Rainy";
  if(s=="Rainy") t="Sunny";
  cout << t << endl;
}
