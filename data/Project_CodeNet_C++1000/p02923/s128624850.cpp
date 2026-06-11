#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;

  vector<ll> h(n+1);

  rep(i, n) cin >> h.at(i);

  h.at(n) = 10000000000;

  int ans = 0;
  int now = 0;

  for(int i = 0; i<n ; i++){
    if(h.at(i) >= h.at(i+1)){
      now++;
    }
    else
    {
      ans = max(now, ans);
      now = 0;
    }
  }

  cout << ans;
}
