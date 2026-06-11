#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string s;
  cin >> s;
  if (s[0] >= 'a' && s[0] <= 'z')
    cout << "a" << endl;
  else if (s[0] >= 'A' && s[0] <= 'Z')
    cout << "A" << endl;
  return 0;
}