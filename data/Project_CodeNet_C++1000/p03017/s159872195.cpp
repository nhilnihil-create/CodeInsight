#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s;
  cin >> s;
  rep2(i, a, max(c, d)){
    if(s.at(i) == '#' && s.at(i+1) == '#'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(c < d){
    cout << "Yes" << endl;
    return 0;
  }

  rep2(i, b, d+1){
    if(s.at(i-1) == '.' && s.at(i) == '.' && s.at(i+1) == '.'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}