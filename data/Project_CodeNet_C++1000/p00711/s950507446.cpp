#include <bits/stdc++.h>
typedef std::pair<int, int> P;

int W = 0;
int H = 0;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void display(std::string *tile){
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      std::cout << tile[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

P getStart(std::string *tile){
  P start;
  bool flag = false;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(tile[i][j] == '@'){
        start.first = i;
        start.second = j;
        flag = true;
        break;
      }
      if(flag) break;
    }
  }
  return start;
}

int main(){
  while(1){
    std::cin >> W >> H;
    if(W + H == 0) break;
    std::vector<std::string> tile(H);
    for(int i = 0; i < H; i++){
      std::cin >> tile[i];
    }

    //display(tile.data());
    P s = getStart(tile.data());

    std::vector<std::vector<bool> > visited(H, std::vector<bool>(W, false));

    std::queue<P> que;
    que.push(s);
    int ans = 1;
    while(que.size()){
      P now = que.front();que.pop();
      for(int i = 0; i < 4; i++){
        int nx = now.second + dx[i], ny = now.first + dy[i];
        if(0 <= nx && nx < W && 0 <= ny && ny < H && !visited[ny][nx] && tile[ny][nx] == '.'){
          que.push(P(ny, nx));
          visited[ny][nx] = true;
          ans++;
        }
      }
    }
    
    std::cout << ans << std::endl;
    
  }
  
  return 0;
}