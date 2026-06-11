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
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int p[100005];
ll x[100005];
multiset<int> st;
ll ans;

int main(void) {
  int N;
  cin >> N;

  rep(i, 0, N) cin >> p[i];
  rep(i, 0, N) x[p[i]] = (ll)i;
  rep(i, 0, 2) st.insert(-1), st.insert(N);

  for (int i=N; i>=1; i--) {
      multiset<int>::iterator itr1, itr2;
      ll LL, LR, RL, RR;

      ll t = x[i];
      itr1 = itr2 = st.lower_bound(t);
      RL = *itr1, RR = *(++itr1);
      LR = *(--itr2), LL = *(--itr2);
      ans += (RR-RL)*(t-LR)*i;
      ans += (LR-LL)*(RL-t)*i;
      st.insert(t);
  }
  
  
  
  cout << ans << endl;
    return 0;
}



