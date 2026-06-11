
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define down_queue(x) priority_queue<x>
#define up_queue(x) priority_queue<x, vector<x>, greater<x>>
#define vec(x) vector<x>
ll gcd(ll a,ll b){while(b){ll tmp = a % b;a = b;b = tmp;}return a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
#define rep(x, y) for(int x = 0; x < (y); x++)
#define REP(x, z, y) for(int x = (z); x < (y); x++)
#define all(x) x.begin(), x.end()
#define split_str(str, sp_word) istringstream stream(str); string res; for(int cnt = 0; getline(stream,res,sp_word); cnt++)
#define digit(x) ((int)log10((double)(x)) + 1)
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define out(x) for(auto i : x) cout << i << " "; cout << endl;
#define outln(x) for(auto i : x) cout << i << " " << endl;
#define vec_cpy(to,from) copy(all(to),back_inserter(from))
#define ary_cpy(to,from) memcpy(to, from, sizeof from)
#define MOD = 1000000007; 
#ifdef DEBUG
#define debug_echo(e) cout << "L" << __LINE__ << ": " << e << endl
#define debug_var(e) cout << "L" << __LINE__ << ": " << #e << " = " << e << endl
#else
#define debug_echo(e)
#define debug_var(e)
#endif

#define MAX_N 50000
#define MAX_M 20

int N;
int M;
int c[MAX_M];

int dp[MAX_N+1];

int solve() {
  for (int i=0; i<M; i++) {
    for (int j=c[i]; j<=N; j++) {
      if (dp[j] == 0) {
        dp[j] = dp[j-c[i]] + 1;
      } else {
        dp[j] = min(dp[j], dp[j-c[i]] + 1);
      } 
    }
  }
}

int main() {
  cin >> N >> M;
  rep(i, M) {
    cin >> c[i];
  }
  memset(dp, 0, sizeof(dp));
  solve();
  rep(i, N+1) {
    debug_echo(i << " " << dp[i]);
  }
  cout << dp[N] << endl;
}