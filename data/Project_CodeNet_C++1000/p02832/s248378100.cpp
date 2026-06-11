#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int now = 1;
  REP(i,n){
    if(a[i] != now) continue;
    now++;
  }

  if(now == 1){
    cout << -1 << endl;
    return 0;
  }

  int ans = n + 1 - now;

  cout << ans << endl;
  return 0;
}
