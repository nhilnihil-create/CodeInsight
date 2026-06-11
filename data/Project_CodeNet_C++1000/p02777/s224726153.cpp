#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s, t;
  cin >> s >> t;
  int a, b;
  cin >> a >> b;
  string u;
  cin >> u;
  if(s == u) a -= 1;
  else if(t == u) b -= 1;
  cout << a << " " << b << endl;
  return 0;
}