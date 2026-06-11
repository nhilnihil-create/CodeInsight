#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,int>;
using T = tuple<string,int,int>;

int main(){
  int n; cin >> n;
  vector<P> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].first >> p[i].second;
  }
  string x; cin >> x;
  int ans = 0;
  bool flg = false;
  for(int i = 0; i < n; i++){
    if(flg){
      ans += p[i].second;
    }
    if(p[i].first == x) flg = true;
  }
  cout << ans << endl;
  return 0;
}
