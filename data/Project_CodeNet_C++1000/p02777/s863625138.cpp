#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  string s, t;
  int a, b;
  string u;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;
  if (u==s)
    cout << a-1 << " " << b << endl;
  else if (u==t)
    cout << a << " " << b-1 << endl;
  return 0;
}
