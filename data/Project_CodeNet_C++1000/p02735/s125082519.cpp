#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int h, w;
vector<string> s;

int main(void){
  cin >> h >> w;
  s = vector<string>(h);
  for(int i = 0; i < h; i++) cin >> s[i];
  vector<vector<int>> z(h+1, vector<int>(w+1, INF));
  if(s[0][0] == '#') z[0][0] = 1;
  else z[0][0] = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '.'){
        if(i+1 < h && s[i+1][j] == '#'){
            z[i+1][j] = min(z[i+1][j], z[i][j]+1);
        }else{
            z[i+1][j] = min(z[i+1][j], z[i][j]);
        }
        if(j+1 < w && s[i][j+1] == '#'){
            z[i][j+1] = min(z[i][j+1], z[i][j]+1);
        }else{
            z[i][j+1] = min(z[i][j+1], z[i][j]);
        }
      }else{
          if(i+1 < h) z[i+1][j] = min(z[i+1][j], z[i][j]);
          if(j+1 < w) z[i][j+1] = min(z[i][j+1], z[i][j]);
      }
    }
  }
  cout << z[h-1][w-1] << endl;
  return 0;
}
