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

using P = pair<ll, ll>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int n, v[5], k[5];
map<int, int> m;


int main(void) {
  cin >> n;
  
  rep(i, 0, n) {
    int a;
    cin >> a;
    m[a]++;
  }
  
  if (sz(m)>3) {
    puts("No");
    return 0;
  }
  int i = 0;
  for (auto itr=m.bg; itr!=m.en; itr++) {
    k[i] = itr->first;
    v[i] = itr->second;
    i++;
  }
  
  bool ok = false;
  
  if (i==1) {
    if (k[0]==0) ok = true;
  } else if (i==2) {
    if (v[1]>v[0]) {
      swap(k[0], k[1]);
      swap(v[0], v[1]);
    }
    if (k[1]==0 && (v[0]+v[1])%3==0 && v[0]==v[1]*2) ok = true;
  } else {
  if ((k[0]^k[1])==k[2] && v[0]==v[1] && v[0]==v[2]) ok = true;
  }
  if(ok) puts("Yes");
  else puts("No");
    

    return 0;
}

