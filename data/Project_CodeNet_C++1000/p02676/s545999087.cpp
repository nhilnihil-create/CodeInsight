#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int k;
  string s;
  cin >> k >> s;
  if (s.length() <= k)
  {
    cout << s << endl;
  }
  else
  {
    cout << s.substr(0, k) << "..." << endl;
  }
}
