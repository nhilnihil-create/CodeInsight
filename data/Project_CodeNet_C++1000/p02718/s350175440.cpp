#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int sum = 0;
  REP(i,n) sum += a[i];
  int cnt = 0;
  REP(i,n){
    if(4 * m * a[i] >= sum) ++cnt;
  }

  if (cnt >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
