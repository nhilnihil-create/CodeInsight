#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  int h, w, ans = 0; cin >> h >> w;
  char c[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> c[i][j];
    }
  }
  vector<vector<pair<int, int> > > hz(h), v(w);
  vector<vector<int> > hz2(h, vector<int>(w, 0)), v2(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    int s = 0;
    for(int j = 0; j < w; j++){
      if(c[i][j] == '#'){
        if(j != s){
          hz[i].push_back(make_pair(s, j - 1));
          for(int k = s; k <= j - 1; k++){
            hz2[i][k] = j - s;
          }
        }
        s = j + 1;
      }
    }
    if(s != w){
      hz[i].push_back(make_pair(s, w - 1));
      for(int k = s; k <= w - 1; k++){
        hz2[i][k] = w - s;
      }
    }
  }
  for(int i = 0; i < w; i++){
    int s = 0;
    for(int j = 0; j < h; j++){
      if(c[j][i] == '#'){
        if(j != s){
          v[i].push_back(make_pair(s, j - 1));
          for(int k = s; k <= j - 1; k++){
            v2[k][i] = j - s;
          }
        }
        s = j + 1;
      }
    }
    if(s != h){
      v[i].push_back(make_pair(s, h - 1));
      for(int k = s; k <= h - 1; k++){
        v2[k][i] = h - s;
      }
    }
  }
  /*for(int i = 0; i < h; i++){
    for(int j = 0; j < hz[i].size(); j++){
      cout << hz[i][j].first << " ~ " << hz[i][j].second << endl;
    }
  }
  for(int i = 0; i < w; i++){
    for(int j = 0; j < v[i].size(); j++){
      cout << v[i][j].first << " ~ " << v[i][j].second << endl;
    }
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << hz2[i][j] << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }*/
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      ans = max(ans, hz2[i][j] + v2[i][j] - 1);
    }
  }
  cout << ans << endl;

  return;
}

int main(){
  solve();
  return 0;
}
