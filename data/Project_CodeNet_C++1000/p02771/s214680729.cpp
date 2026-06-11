#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
  bool s = true;
  int a,b,c;
  cin >> a >> b >> c;
  if(a == b && b == c) s = false;
  if(a != b && b != c && c != a) s = false;
  if(s) cout << "Yes" << endl;
  else cout << "No" << endl;
return 0;
}