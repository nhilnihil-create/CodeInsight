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
  vector<int> w(n);
  REP(i,n) cin >> w[i];
  int s1 = 0;
  int s2 = 0;
  int mx = 1000000;
  for(int i = 0; i < n ; ++ i){
    s1 = 0; s2 = 0;
    for(int j = 0; j < i; ++ j) s1 += w[j];
    for(int j = i; j < n; ++ j) s2 += w[j];
    //cout << s1 << " " << s2 << endl;
    mx = min(mx, abs(s1-s2));
  }

  cout << mx << endl;
  return 0;
}