#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  int s;
  cin >> s;
  s %= 10;
  if (s == 2 || s == 4 || s == 5 || s == 7 || s == 9)
  {
    cout << "hon";
  }
  if (s == 0 || s == 1 || s == 6 || s == 8)
  {
    cout << "pon";
  }
  if (s == 3)
  {
    cout << "bon";
  }
}
