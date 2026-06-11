#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  REP(i,n) cin >> v[i];

  sort(ALL(v));

  double ans = v[0];
  // if(n == 1){
  //   cout<< fixed << setprecision(10) << ans << endl;
  //   return 0;
  // }

  for(int i = 1; i < n; ++i){
    ans =  (ans + v[i])/2;
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}