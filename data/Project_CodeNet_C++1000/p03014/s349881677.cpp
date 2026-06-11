#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<typename T>
std::vector<std::vector<T>> mk2d(size_t s1, size_t s2, T const& val) {
  std::vector<T> tmp(s2, val);
  return std::vector<std::vector<T>>(s1, tmp);
}

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int H, W; std::cin >> H >> W;
  auto wall = mk2d<bool>(H, W, false);
  for(int i = 0; i < H; ++i) {
    std::string S; std::cin >> S;
    for(int j = 0; j < W; ++j) wall[i][j] = (S[j]=='#');
  }
  auto lh = mk2d<int>(H,W,0), lv = mk2d<int>(H,W,0);
  for(int i = 0; i < H; ++i) {
    int last = 0;
    bool pre = true;
    for(int j = 0; j < W; ++j) if(wall[i][j] != pre) {
      if(wall[i][j]) {
        int v = j-last;
        for(int k = last; k < j; ++k) lh[i][k] = v;
      } else last = j;
      pre = wall[i][j];
    }
    if(!wall[i][W-1]) {
      int v = W-last;
      for(int k = last; k < W; ++k) lh[i][k] = v;
    }
  }
  for(int j = 0; j < W; ++j) {
    int last = 0;
    bool pre = true;
    for(int i = 0; i < H; pre = wall[i++][j]) if(wall[i][j] != pre) {
      if(wall[i][j]) {
        int v = i-last;
        for(int k = last; k < i; ++k) lv[k][j] = v;
      } else last = i;
    }
    if(!wall[H-1][j]) {
      int v = H-last;
      for(int k = last; k < H; ++k) lv[k][j] = v;
    }
  }
  int ans = 0;
  for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) {
    ans = std::max(ans, lh[i][j]+lv[i][j]-1);
  }
  fin(ans);
  return 0;
}
