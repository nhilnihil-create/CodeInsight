#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h+1);
  vector<vector<int>> mass(h, vector<int>(w, 0));
  rep(i, h){
    cin >> s[i];
    s[i].push_back('#');
  }
  string t(w+1, '#');
  s[h] = t;
  rep(i, h+1){
    int len;
    bool flag = true;
    rep(j, w+1){
      if (s[i][j] == '#'){
        if (!flag){
          rep2(k, j-len, j){
            mass[i][k] += len;
          }
          flag = true;
        }
      }
      else{
        if (flag){
          len = 1;
          flag = false;
        }
        else len++;
      }
    }
  }
  
  rep(i, w+1){
    int len;
    bool flag = true;
    rep(j, h+1){
      if (s[j][i] == '#'){
        if (!flag){
          rep2(k, j-len, j){
            mass[k][i] += len;
          }
          flag = true;
        }
      }
      else{
        if (flag){
          len = 1;
          flag = false;
        }
        else len++;
      }
    }
  }
  int ans = 0;
  rep(i, h)rep(j, w) ans = max(ans, mass[i][j]-1);
  cout << ans << endl;
  
  return 0;
}