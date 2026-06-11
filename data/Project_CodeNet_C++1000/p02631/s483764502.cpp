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
  int axor = 0;
  rep(i, n)
    axor ^= a[i];
  rep(i, n)
    printf("%d%c", axor ^ a[i], i < n - 1 ? ' ' : '\n');
  return 0;
}