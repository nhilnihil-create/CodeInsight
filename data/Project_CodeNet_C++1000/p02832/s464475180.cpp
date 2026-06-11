#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];
  int ans = 0;
  int id = 0;
  int i = 1;
  while (true)
  {
    while (id < n && a[id] != i)
    {
      id++;
      ans++;
    }
    if (id == n)
      break;
    i++;
    id++;
  }
  if (i == 1)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}