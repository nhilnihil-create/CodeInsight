#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s, t;
  cin >> s >> t;
  cout << 3 - (bool)(s[0] ^ t[0]) - (bool)(s[1] ^ t[1]) - (bool)(s[2] ^ t[2]) << endl;
  return 0;
}