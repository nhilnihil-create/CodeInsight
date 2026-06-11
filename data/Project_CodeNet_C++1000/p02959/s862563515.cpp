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
  vector<int> a(n+1);
  vector<int> b(n);
  REP(i,n+1) cin >> a[i];
  REP(i,n) cin >> b[i];
  b.push_back(0);

  ll sum = 0;

  REP(i,n){

    if(b[i]-a[i] <= 0){
      sum += b[i];
    }
    else if(b[i]-a[i] > 0){
      sum += a[i];
      sum += min(b[i]-a[i],a[i+1]);
      a[i+1] = max(0, a[i+1]-b[i] + a[i]);
    }
    // cout << sum << endl;
  }

  cout << sum << endl;


  return 0;
}
