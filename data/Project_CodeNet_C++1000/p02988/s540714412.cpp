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
  vector<int> p(n);
  REP(i, n) cin >> p[i];
  int cnt = 0;
  for(int i = 1; i < n-1; ++i){
    if(p[i] > p[i-1] && p[i] < p[i+1]) ++cnt;
    if(p[i] < p[i-1] && p[i] > p[i+1]) ++cnt;
  }

  cout << cnt << endl;



  return 0;
}
