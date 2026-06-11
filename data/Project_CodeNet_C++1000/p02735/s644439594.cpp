#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int BFS(const vector<string> &board){
  using coord= pair<int, int>;
  constexpr char block= '#';
  constexpr int TBC= INT_MAX;
  const vector<coord> diff= {make_pair(1,0), make_pair(0,1)};

  const int H= board.size();
  const int W= board.at(0).size();
  const coord start= make_pair(0, 0);
  const coord goal = make_pair(H-1, W-1);

  vector<vector<int>> dist(H, vector<int>(W, TBC));
  dist.at(0).at(0)= (board.at(0).at(0)==block) ? 1
                                               : 0;
  deque<coord> bfs;
  bfs.push_front(start);
  while( !bfs.empty() ){
    coord p= bfs.front();
    bfs.pop_front();
    int x,y;
    tie(x,y)= p;
    for(auto &ds:diff){
      int dx,dy;
      tie(dx,dy)= ds;
      if(x+dx <= -1 || x+dx >= H || y+dy <= -1 || y+dy >= W) continue;
      else if(dist.at(x+dx).at(y+dy) > dist.at(x).at(y)+ 1 && board.at(x+dx).at(y+dy)==block && board.at(x).at(y) != block){
        dist.at(x+dx).at(y+dy)= dist.at(x).at(y)+ 1;
        bfs.push_back(make_pair(x+dx, y+dy));
      }
      else if(dist.at(x+dx).at(y+dy) > dist.at(x).at(y) && !(board.at(x+dx).at(y+dy)==block && board.at(x).at(y) != block)){
        dist.at(x+dx).at(y+dy)= dist.at(x).at(y);
        bfs.push_front(make_pair(x+dx, y+dy));
      }
    }
  }

  return dist.back().back();
}

int main(){
  int H,W;
  cin >> H >> W;

  vector<string> data(H);
  for(int i=0; i<H; i++){
    cin >> data.at(i);
  }

  int ans= BFS(data);
  
  cout << ans << endl;
}