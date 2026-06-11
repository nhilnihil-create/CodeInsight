#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> gr;
  int ans = 0;
  int add = 1;
  rep2(i, 1, s.size()){
    if(s.at(i-1) != s.at(i)){
      gr.push_back(add);
      ans += add-1;
      add = 1;
    }else add++;
  }
  gr.push_back(add);
  ans += add-1;
  cerr << ans << " " << gr.size() << endl;
  ans = min(n-1, ans + 2*k);
  cout << ans << endl;
  return 0;
}