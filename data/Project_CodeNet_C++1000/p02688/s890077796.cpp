#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, k;
  cin >> n >> k;
  vector<int> snuke(n);

  REP(i,k){
    int d;
    cin >> d;
    REP(j,d){
      int a;
      cin >> a;
      --a;
      ++snuke[a];
    }
  }
  int ans = 0;
  REP(i,n){
    if(snuke[i] == 0) ++ans;
  }

  cout << ans << endl;
  return 0;
}