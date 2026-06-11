#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  ll ans = 0;
  ll x = 100;
  while(n > x){
    x = x + x / 100;
    ans++;
  }
  cout << ans << endl;
  return 0;
}