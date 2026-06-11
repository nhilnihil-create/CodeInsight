#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  rep(i, n)
  {
    int A;
    cin >> A;
    a[i+1] = a[i] + A - 1;
  }
  map<ll, int> mp;
  ll ans = 0;
  rep(i, n + 1)
  {
    if (i >= k)
      mp[a[i-k]%k]--;
    ans += mp[a[i]%k];
    mp[a[i]%k]++;
  }
  cout << ans << endl;
  return 0;
}