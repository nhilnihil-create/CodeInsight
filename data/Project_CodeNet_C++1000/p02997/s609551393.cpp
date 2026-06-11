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
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

static const long long MOD = 998244353;


int n, k;
vector<pair<int, int> > vec;

int main(void) {
  cin >> n >> k;
  
  for (int i=2; i<=n; i++) vec.pb(mp(1, i));
  int t = ((n-1)*(n-2))/2;
  
  int u = 2, v = u + 1;
  while (t>k) {
    vec.pb(mp(u, v));
    t--;
    v++;
    if (v>n) {
      u++;
      v = u + 1;
    }
  }
  
  if (t!=k) puts("-1");
  else { 
    cout << sz(vec) << "\n";
    for (auto p : vec) printf("%d %d\n", p.first, p.second);
  }

    return 0;
}

