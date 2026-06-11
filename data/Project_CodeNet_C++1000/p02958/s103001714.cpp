#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){

  int n;
  cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  int cnt = 0;

  REP(i,n){
    --p[i];
    if(p[i] != i) ++cnt;
  }

  if(cnt == 0 || cnt == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  //cout << cnt << endl;

  return 0;
}