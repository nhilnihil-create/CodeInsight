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

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int n, m;
string s;
vector<int> ans;

int main(void) {
  cin >> n >> m >> s;
  
  int pos = n;
  while (pos>0) {
    bool ok = false;
    for (int i=m; i>=1; i--) {
      if (s[pos-i]=='0' || pos-i<=0) {
        if (pos-i<=0) ans.pb(pos);
        else ans.pb(i);
        
        pos = max(pos-i, 0);
        ok = true;
        break;
      }
      
      
    
    }
    if (!ok) {
        puts("-1");
        return 0;
      }
  
  }
  reverse(ans.bg, ans.en);
  for (int i=0; i<sz(ans); i++) {
    if (i>0) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  
  
   return 0;
}

