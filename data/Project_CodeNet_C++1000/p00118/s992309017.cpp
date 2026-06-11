#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char kind[] = {'#', '@', '*'};


int INF = 1 << 10;

vector<string> field(101);

void display(int h, int w){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << field[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void dfs(int h, int w, char c, P s){
  field[s.first][s.second] = '.';
  for(int i = 0; i < 4; i++){
    int nx = s.second + dx[i], ny = s.first + dy[i];
    if(0 <= nx && nx < w && 0 <= ny && ny < h && field[ny][nx] == c){
      dfs(h, w, c, P(ny, nx));
    }
  }
}

P getStart(int h, int w, char c){
  bool flag = false;
  P res(INF, INF);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(field[i][j] == c){
        res.first = i;
        res.second = j;
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  return res;
}

int main(){
  int h, w;

  while(1){
    cin >> h >> w;
    if(h == 0 && w == 0) break;
    
    for(int i = 0; i < h; i++){
      cin >> field[i];
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
      char c = kind[i];
      while(1){
        P s = getStart(h, w, c);
        if(s == P(INF, INF)) break;
        dfs(h, w, c, s);
        ans++;
      }
    }

    cout << ans << endl;
  }
  
  return 0;
}