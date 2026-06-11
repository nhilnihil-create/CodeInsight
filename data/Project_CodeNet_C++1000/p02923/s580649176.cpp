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
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  int MXSTEP = 0;
  int cnt = 0;

  for(int i = 1; i < n; i++){
    if(h[i] <= h[i-1]){
      cnt++;
    }
    else{
      MXSTEP = max(MXSTEP, cnt);
      cnt = 0;
    }
  }

  MXSTEP = max(MXSTEP, cnt);

  cout << MXSTEP << endl;
  return 0;
}