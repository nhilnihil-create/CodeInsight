#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<vector<P>> human(n);
  rep(i, n){
    int a; cin >> a;
    rep(j, a){
      int x, y;
      cin >> x >> y;
      x--;
      human[i].push_back(P(x, y));
    }
  }
  
  int ans = 0;
  rep(i, 1<<n){
    bool flag = true;
    int now = 0;
    rep(j, n){
      if ((i>>j)&1){
        now++;
        for(P xy : human[j]){
          if (((i>>xy.first)&1) != xy.second){
            flag = false;
            break;
          }
        }
      }
      if (!flag) break;
    }
    if (flag) ans = max(ans, now);
  }
  cout << ans << endl;
  
  return 0;
}