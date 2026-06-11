#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, m;

  int sum = 0;

  cin >> n >> m;
  rep(i, n)
  {
    sum += i;
  }
  rep(i, m)
  {
    sum += i;
  }

  cout << sum;
}
