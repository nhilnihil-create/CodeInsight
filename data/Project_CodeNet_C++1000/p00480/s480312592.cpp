#include <bits/stdc++.h>
using namespace std;

#define int long long 

int n;
int a[100];

int po[128][32];

int dfs(int i, int sum)
{
  if (sum < 0 || sum > 20) return 0;
  if (i == n - 1) {
    return sum == a[n - 1];
  }

  int &ret = po[i][sum];
  if (ret != -1) return ret;
  ret = dfs(i + 1, sum + a[i]) + dfs(i + 1, sum - a[i]);
  return ret;
}

main()
{
  memset(po, -1, sizeof(po));
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  cout << dfs(1, a[0]) << endl;
}