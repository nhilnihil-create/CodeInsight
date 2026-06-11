#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= 9; i++)
  {
    int buf = n;
    if (buf % i == 0)
    {
      if (buf / i >= 1 && buf / i <= 9)
      {
        ans = 1;
      }
    }
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
