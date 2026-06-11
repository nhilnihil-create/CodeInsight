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
  int n;
  cin >> n;
  string s = "", t = "";
  rep(i, n){
    char c;
    cin >> c;
    s.push_back(c);
  }
  rep(i, n){
    char c;
    cin >> c;
    t.push_back(c);
  }
  string p = "";
  rep(i, n)p.push_back('0'+i+1);
  int ans = -1, co = 0;
  if(s == t){
    cout << 0 << endl;
    return 0;
  }
  do{
    co++;
    if(p == s || p == t){
      if(ans == -1) ans = co;
      else {
        cout << co - ans << endl;
        break;
      }
    }
  }while(next_permutation(ALL(p)));
  return 0;
}