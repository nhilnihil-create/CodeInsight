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
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  int now = n;
  stack<int> stk;
  while(1){
    int bf = now;
    rrep2(i, 1, m+1){
      if(now - i >= 0 && s.at(now-i) == '0'){
        stk.push(i);
        now = now - i;
        break;
      }
    }
    if(bf == now){
      cout << -1 << endl;
      return 0;
    }
    if(now == 0) break;
  }
  bool f = false;
  while(!stk.empty()){
    if(f != false) cout << " ";
    cout << stk.top();
    stk.pop();
    if(f == false) f = true;
  }
  cout << endl;
  return 0;
}