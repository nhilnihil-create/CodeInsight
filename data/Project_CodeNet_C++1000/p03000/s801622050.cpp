#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  REP(i,n) cin >> l[i];
  int d = 0;
  int cnt = 1;
  REP(i,n){
    d += l[i];
    if(d <= x) ++cnt;
    else break;
  }

  cout << cnt << endl;
  return 0;
}