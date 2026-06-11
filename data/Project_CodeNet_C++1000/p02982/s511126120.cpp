#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, d;
  cin >> n >> d;
  int x[n][d];

  REP(i,n){
    REP(j,d) cin >> x[i][j];
  }

  int cnt = 0;
  REP(i,n){
    for(int k = i + 1; k < n; ++k){
      int sum = 0;
      REP(j,d){
        int diff =abs(x[i][j]-x[k][j]);
        sum += (diff * diff);
      }
      for(int pi = 0; pi*pi <= sum; ++pi){
        if(sum == pi*pi) ++cnt;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}