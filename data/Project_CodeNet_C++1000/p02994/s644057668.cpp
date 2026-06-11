#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, l;
  cin >> n >> l;
  int s = l * (n - 1) + (n - 1) * n / 2;
  if (l < 0)
    s -= min(-l, n - 1);
  cout << s << endl;
  return 0;
}