#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> mp;
  rep(i, h){
    string str;
    cin >> str;
    mp.push_back(str);
  }
  vector<vector<int>> row(h, vector<int>(w, 0));
  vector<vector<int>> col(h, vector<int>(w, 0));
  bool light = false;
  int cnt = 0;
  rep(i, h){
    light = false;
    cnt = 0;
    rep(j, w){
      if(mp[i][j] == '.'){
        if(light){
          cnt++;
        }else{
          light = true;
          cnt = 1;
        }
      }else{
        if(light){
          light = false;
          for(int k=1; k<=cnt; k++) row[i][j-k] = cnt;
        }
      }
    }
    if(light){
      light = false;
      for(int k=1; k<=cnt; k++) row[i][w-k] = cnt;
    }
  }
  light = false;
  cnt = 0;
  rep(j, w){
    light = false;
    cnt = 0;
    rep(i, h){
      if(mp[i][j] == '.'){
        if(light){
          cnt++;
        }else{
          light = true;
          cnt = 1;
        }
      }else{
        if(light){
          light = false;
          for(int k=1; k<=cnt; k++) col[i-k][j] = cnt;
        }
      }
    }
    if(light){
      light = false;
      for(int k=1; k<=cnt; k++) col[h-k][j] = cnt;
    }
  }
  int biggest = 0;
  rep(i, h)
    rep(j, w)
      biggest = max(biggest, row[i][j]+col[i][j]-1);
  cout << biggest << endl;
  return 0;
}