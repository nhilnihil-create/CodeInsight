#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
  int n,m;
  cin >> n >> m;
  int ans = 0;
  ans += (n*(n-1))/(1*2);
  ans += (m*(m-1))/(1*2);
  cout << ans << endl;
return 0;
}