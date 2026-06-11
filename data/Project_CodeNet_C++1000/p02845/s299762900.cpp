
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int) (v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int n, a[100005];
int s[5];

int main(void) {
  cin >> n;
  rep(i, 0, n) scanf("%d", &a[i]);
  ll ans = 1;
  for(int i=0; i<n; i++) {
    ll c = 0;
    for (int j=0; j<3; j++) if (s[j] == a[i]) c++;
    ans *= c;
    ans %= MOD;
    for (int j=0; j<3; j++) {
      if (s[j] == a[i]) {
        s[j]++;
        break;
      }
    }
  }
  printf("%lld\n", ans%MOD);
  
  return 0;
}
