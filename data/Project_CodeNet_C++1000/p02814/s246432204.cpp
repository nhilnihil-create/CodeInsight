#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e5+1;
int n, m;
long a[N];

int main()
{
  fastio;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i]; a[i] /= 2;
  }
  while (true){
    bool Check = a[1] % 2;
    for (int i = 1; i <= n; i++){
      if (a[i] % 2 != Check) return cout << 0, 0;
      if (Check == false) a[i] /= 2;
    }
    if (Check) break;
    else m /= 2;
  }
  long lcm = 1;
  for (int i = 1; i <= n; i++){
    lcm = lcm * a[i] / __gcd(lcm, a[i]);
    if (lcm > m) return cout << 0, 0;
  }
  cout << (m / lcm + 1) / 2;
  return 0;
}