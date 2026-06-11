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

const int N = 10001;
string s; 
int p, cnt[N];

int main()
{
  fastio;
  int n;
  cin >> n >> p >> s;
  reverse(all(s));
  if (p == 2 || p == 5){
    long res = 0;
    for (int i = 0; i < n; i++){
      int x = s[i] - '0';
      if (x % p == 0) res += 1ll * (n - i);
    }
    cout << res; return 0;
  }
  long meow = 1; long cur = 0;
  long res = 0;  cnt[0] = 1;
  for (int i = 0; i < n; i++){
    int x = s[i] - '0';
    cur = (cur + meow * x) % p;
    (meow *= 10) %= p;
    res += cnt[cur];
    cnt[cur]++;
  }
  cout << res;
 
  return 0;
}