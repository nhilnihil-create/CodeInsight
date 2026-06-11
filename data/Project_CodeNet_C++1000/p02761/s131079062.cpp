#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  int N, M; cin >> N >> M;
  vector<int> s(M);
  vector<int> c(M);
  rep(i, M) cin >> s.at(i) >> c.at(i);
  vector<int> num(N,-1);
  bool ok = true;
  rep(i, M){
    if(num.at(s.at(i)-1)==-1) {
      num.at(s.at(i)-1) = c.at(i);
    } else if (num.at(s.at(i)-1) == c.at(i)){
      num.at(s.at(i)-1) = c.at(i);
    } else {
      ok = false;
      break;
    }
  }
  int ans = 0;
  if(N != 1 && num.at(0) == 0) ok = false;
  if(N != 1 && num.at(0) == -1) num.at(0) = 1;
  rep(i, N) if(num.at(i) == -1) num.at(i) = 0;
  if(ok){
    rep(i, N) ans += num.at(i) * pow(10, N-1-i);
  } else {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}