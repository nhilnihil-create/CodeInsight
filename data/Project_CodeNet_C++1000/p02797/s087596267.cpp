#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  ll n, k, s; cin >> n >> k >> s;
  rep(i, k) {
    if (i > 0) cout << " ";
    cout << s;
  }
  rep(i, n-k) {
    if (s < 1000000000) cout << " " << s+1;
    else cout << " 1";
  }
  cout << endl;

  return 0;
}
