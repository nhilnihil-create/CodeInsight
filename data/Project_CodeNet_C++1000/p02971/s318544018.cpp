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
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> b(n);
  b = a;

  sort(ALL(b));
  int MX = *(b.end()-1);
  b.pop_back();
  int MX2 = *(b.end()-1);

  int ans = 0;

  REP(i,n){
    if(a[i] == MX){
      ans = MX2;
    }
    else{
      ans = MX;
    }
    cout << ans << endl;
  }

  return 0;
}