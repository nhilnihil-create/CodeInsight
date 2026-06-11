#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int X[N];
  REP(i,N) cin >> X[i];

  auto mm = minmax_element(X, X+N);
  int ans = INF;
  EACH(p, *mm.first, *mm.second) {
    int sum = 0;
    for(int xi : X) {
      sum += (xi - p) * (xi - p);
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;

  return 0;
}