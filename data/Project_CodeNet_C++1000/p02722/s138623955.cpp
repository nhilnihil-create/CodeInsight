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

long n;

int main()
{
  fastio;
  cin >> n;
  long res = 1; res += (n != 2);
  for (long i = 2; i * i <= n - 1; i++){
    if ((n - 1) % i == 0){
      res++;
      if ((n - 1) / i != i) res++; 
    }
  }
  for (long i = 2; i * i <= n; i++){
    if (n % i == 0){
      long x = n;   
      while (x % i == 0) x /= i; 
      res += (x % i == 1);
      int j = n / i;
      if (i == j) continue;
      x = n;
      while (x % j == 0) x /= j;
      res += (x % j == 1);
    }
  }
  cout << res;
  return 0;
}