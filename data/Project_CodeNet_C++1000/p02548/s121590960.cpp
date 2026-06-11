#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= (n / i); j++)
    {
      if (i * j < n)
      {
        cnt++;
      }
      else
      {
        break;
      }
    }
  }
  cout << cnt << endl;
}
