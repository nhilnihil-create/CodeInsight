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
  vector<int> d(n);
  REP(i,n) cin >> d[i];

  sort(ALL(d));

  int l = d[n/2 -1];
  int r = d[n/2];

  if(l == r) cout << 0 << endl;
  else{
    cout << r -l << endl;
  }

  return 0;
}