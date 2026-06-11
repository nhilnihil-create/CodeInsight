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
  int m = 0;
  vector<int> ans(n);
  for (int i=n; i>0; i--)
  {
    int s = 0;
    for (int j = n - 1 - n % i; j > i - 1; j -= i)
      s += ans[j];
    ans[i-1] = (a[i-1] ^ s % 2) & 1;
    m += ans[i-1];
  }
  printf("%d\n", m);
  int id = 0;
  while (id < n && ans[id] == 0)
    id++;
  if (id < n)
  {
    printf("%d", id + 1);
    for (int i=id+1; i<n; i++)
      if (ans[i] == 1)
        printf(" %d", i + 1);
    printf("\n");
  }
  return 0;
}