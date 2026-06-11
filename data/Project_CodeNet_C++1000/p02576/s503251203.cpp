#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(a,b) for(ll i=a;i<b;i++)
#define endl "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, o;
  cin >> n >> m >> o;
  ll ans = (ceil((float)n / m)) * o;
  cout << ans << endl;

  return 0;
}

