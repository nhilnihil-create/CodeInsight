#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define EPS (1e-7)
#define INF (1e15)
#define PI (acos(-1))
#define MOD 1000000007

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,f,n) for(int i=(f);i<(n);i++)
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define arrdump(n,a) for(int i=0;i<n;i++) {cout<<((i>0)? " ":"")<<a[i];}cout<<"\n";


typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// https://atcoder.jp/contests/abc129/tasks/abc129_c

int main() {
  int N, M; cin >> N >> M;
  int a[N+1]; REP(i, N+1) a[i] = 0;
  REP(i, M) {
    int b; cin >> b;
    a[b] = 1;
  }
  ll dp[N+5]; REP(i, N+5) dp[i] = 0;
  dp[0] = 1;
  dp[1] = 1;

  REP(i, N+1) {
    if (i==0||i==1) continue;
    dp[i] += (a[i-2]?0:dp[i-2]);
    dp[i] %= MOD;
    dp[i] += (a[i-1]?0:dp[i-1]);
    dp[i] %= MOD;
  }
  cout << dp[N] << "\n";
  
  return 0;
}
