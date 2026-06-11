#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (a % 2 == 0)
    {
      if (a % 3 == 0 || a % 5 == 0)
      {
        continue;
      }
      ans = 0;
    }
  }
  if (ans)
  {
    cout << "APPROVED" << endl;
  }
  else
  {
    cout << "DENIED" << endl;
  }
}
