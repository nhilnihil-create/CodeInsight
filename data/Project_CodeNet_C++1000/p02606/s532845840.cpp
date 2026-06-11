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
  int l,r,d;
  cin >> l >> r >> d;
  int cnt = 0;
  REP2(i,l,r+1){
    if(i%d == 0) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
