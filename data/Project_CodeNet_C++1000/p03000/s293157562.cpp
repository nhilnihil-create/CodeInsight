#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> L(n);
  rep(i, n) cin >> L.at(i);

  vector<int> D(n+1);
  D.at(0) = 0;
  rep(i, n)
  {
    D.at(i + 1) = D.at(i) + L.at(i);
  }

  int count = 0;
  rep(i, n+1)
  {
    if (D.at(i) <= x)
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}