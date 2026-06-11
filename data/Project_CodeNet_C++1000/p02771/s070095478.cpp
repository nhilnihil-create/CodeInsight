#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if ((a != b && a != c && b != c) || (a == b && b == c && a == c))
    cout
        << "No";
  else
  {
    cout << "Yes";
  }
}
