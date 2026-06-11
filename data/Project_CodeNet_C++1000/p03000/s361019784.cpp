#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,x,cnt=1;
  cin>>n>>x;

  vector<int> l(n+1),d(n+2);
  l[0] = 0;
  d[0] = 0;
  d[1] = 0;
  for (int i = 1; i <= n; i++) cin >> l[i];

  for (int i = 2; i <= n+1; i++) {
    d[i] = d[i-1] + l[i-1];
    if (d[i] <= x) cnt++;
  }

  cout << cnt << endl;
  return 0;
  

}