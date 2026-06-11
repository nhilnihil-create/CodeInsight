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

const int N = 2e5+1;
int n, k, C, F[N + 1];
char c[N];

int main()
{
  fastio;
  cin >> n >> k >> C;
  for (int i = 1; i <= n; i++) cin >> c[i];
  vector <int> memo;
  int pre = -INF;
  for (int i = 1; i <= n; i++){
    if (c[i] == 'x') continue;
    if (i - C > pre){
      memo.push_back(i);
      pre = i;
    }
    if (memo.size() == k) break;
  }
  if (memo.size() < k) return cout << -1, 0;
  F[n + 1] = 0; pre = INF;
  for (int i = n; i > 0; i--){
    F[i] = F[i + 1];
    if (c[i] == 'x') continue;
    if (i + C < pre){
      pre = i; F[i]++;  
    }  
  }
  for (int i = 0; i < k; i++){
    int cur = memo[i];
    if (i + F[cur + 1] + 1 == k) cout << cur << '\n';
  }
  return 0;
}