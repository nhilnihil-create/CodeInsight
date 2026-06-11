#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> smp(h);
  for(int i=0; i<h; ++i) cin >> smp[i];
  vector<vector<P>> memo(h, vector<P>(w));
  int ans = 0;
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    if(smp[i][j] == '#') continue;
    
    if(i>0 && smp[i-1][j] == '.'){
      memo[i][j].first = memo[i-1][j].first;
    }else{
      int cnt = 0;
      int x = i-1;
      while(x >=0 && smp[x][j] == '.'){
        ++cnt;
        --x;
      }
      x = i+1;
      while(x <h && smp[x][j] == '.'){
        ++cnt;
        ++x;
      }
      memo[i][j].first = cnt + 1;
    }
    
    if(j>0 && smp[i][j-1] == '.'){
      memo[i][j].second = memo[i][j-1].second;
    }else{
      int cnt = 0;
      int y = j-1;
      while(y >=0 && smp[i][y] == '.'){
        ++cnt;
        --y;
      }
      y = j+1;
      while(y <w && smp[i][y] == '.'){
        ++cnt;
        ++y;
      }
      memo[i][j].second = cnt + 1;
    }
    ans = max(ans, memo[i][j].first +memo[i][j].second -1);
    //cout << "i:" << i << " j:" << j << " ans:" << ans << endl;
  }
  cout << ans << endl;
}