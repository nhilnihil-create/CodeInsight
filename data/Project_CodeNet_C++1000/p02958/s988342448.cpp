#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> copy(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
    copy[i] = p[i];
  }
  sort(copy.begin(), copy.end());
  int ng = 0;
  for (int i = 0; i < n; i++)
  {
    if (ng > 2)
    {
      cout << "NO" << endl;
      return 0;
    }

    if (p[i] != copy[i])
    {
      ng++;
    }
  }
  cout << "YES" << endl;
}
