#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int h,w;
  const int max_h = 2 * 1e3;
  string s[max_h + 1];
  cin >> h >> w;
  for(int i = 0; i < h; i++) cin >> s[i];

  vector<vector<int>> h_cnt(max_h + 1, vector<int>(max_h + 1));
  vector<vector<int>> w_cnt(max_h + 1, vector<int>(max_h + 1));
  int cnt = 0;
  int r = 0;

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cnt = 0;
      if(s[i][j] == '#') w_cnt[i][j] = 0;
      if(s[i][j] == '.'){
        r = j;
        while(s[i][j] == '.' && j < w){
          cnt ++;
          j++;
        }
        for(int k = r; k < j; k++){
          w_cnt[i][k] = cnt;
        }
      }
    }
  }
  for(int j = 0; j < w; j++){
    for(int i = 0; i < h; i++){
      cnt = 0;
      if(s[i][j] == '#') h_cnt[i][j] = 0;
      if(s[i][j] == '.'){
        r = i;
        while(s[i][j] == '.' && i < h){
          cnt ++;
          i++;
        }
        for(int k = r; k < i; k++){
          h_cnt[k][j] = cnt;
        }
      }
    }
  }

  long long ans = 0;
  pair<int, int> res;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(h_cnt[i][j] + w_cnt[i][j] > ans){
        res = make_pair(i, j);
        ans = h_cnt[i][j] + w_cnt[i][j] - 1;
      }
    }
  }
  cout << ans << endl;


  
  // for(int i = 0; i < h; i++){
  //   for(int j = 0; j < w; j++){
  //     cout << w_cnt[i][j];
  //   }
  //   cout << endl;
  // }

  // for(int i = 0; i < h; i++){
  //   for(int j = 0; j < w; j++){
  //     cout << h_cnt[i][j];
  //   }
  //   cout << endl;
  // }



  return 0;
}