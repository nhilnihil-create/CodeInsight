#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m; cin >> n >> m;
  int sum = 0;
  for(int i = 0; i < m; i++)
  {
    int x; cin >> x;
    sum += x;
  }
  cout << max(n-sum, -1) << endl;
  return 0;
}