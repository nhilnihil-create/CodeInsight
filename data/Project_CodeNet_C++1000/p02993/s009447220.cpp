#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c,d;
  string ans = "Good";
  cin >> a >> b >> c >> d;
  if (a==b || b == c || c == d) ans = "Bad";
  cout << ans << endl;
}
