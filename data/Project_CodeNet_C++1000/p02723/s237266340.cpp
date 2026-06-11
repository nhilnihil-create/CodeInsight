#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  string s;
  cin >> s;

  if(s.at(2) == s.at(3) && s.at(4) == s.at(5))
    cout << "Yes";
  else
  {
    cout << "No";
  }

}
