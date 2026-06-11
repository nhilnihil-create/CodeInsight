#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string T;
  cin >> T;

  REP(i, T.length())
  {
    if (T[i] == 'P')
      cout << "P";
    else
      cout << "D";
  }
  cout << endl;

  return 0;
}