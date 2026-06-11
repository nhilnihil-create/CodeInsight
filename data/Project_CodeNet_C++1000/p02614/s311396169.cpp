#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int h, w, K; cin >> h >> w >> K;
  vector<string> s(h);
  for(int i = 0; i < h; i++){
    cin >> s[i];
  }  

  int ans = 0;
  for(int i = 0; i < 1 << h; i++){
    for(int j = 0; j < 1 << w; j++){
      auto t = s;
      for(int k = 0; k < h; k++){
        if(i >> k & 1){
          for(int l = 0; l < w; l++){
            t[k][l] = '.';
          }
        }
      }
      for(int k = 0; k < w; k++){
        if(j >> k & 1){
          for(int l = 0; l < h; l++){
            t[l][k] = '.';
          }
        }
      }

      int cnt = 0;
      for(int k = 0; k < h; k++){
        for(int l = 0; l < w; l++){
          cnt += (t[k][l] == '#');
        }
      }
      if(cnt == K) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}