#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  string s,t;
  cin >> s >> t;
  ll a,b;
  cin >> a >> b;
  string u;
  cin >> u;
  if(u==s) a--;
  if(u==t) b--;
  cout << a << " " << b << endl;
}