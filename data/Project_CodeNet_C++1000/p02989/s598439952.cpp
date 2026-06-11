#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll d[n];
  rep(i,n) cin >> d[i];
  
  sort(d,d+n);
  
  int ans = 0;
  cout << d[n/2] - d[n/2-1] << endl;
}
