#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

const int SIZE = 2001;

int H, W;
int LEFT[SIZE][SIZE], RIGHT[SIZE][SIZE], UP[SIZE][SIZE], DOWN[SIZE][SIZE];
char field[SIZE][SIZE];

void init(){
  // left
  rep(i, H){
    int cur = 0;
    rep(j, W){
      if(field[i][j]=='#'){
        cur=0;
      }else{
        cur++;
      }
      LEFT[i][j] = cur;
    }
  }
  // right
  rep(i, H){
    int cur = 0;
    rep(j, W){
      if(field[i][W-1-j]=='#'){
        cur=0;
      }else{
        cur++;
      }
      RIGHT[i][W-1-j] = cur;
    }
  }
  // down
  rep(j, W){
    int cur = 0;
    rep(i, H){
      if(field[i][j]=='#'){
        cur=0;
      }else{
        cur++;
      }
      DOWN[i][j] = cur;
    }
  }
  // up
  rep(j, W){
    int cur = 0;
    rep(i, H){
      if(field[H-1-i][j]=='#'){
        cur=0;
      }else{
        cur++;
      }
      UP[H-1-i][j] = cur;
    }
  }
}

int calc(int h, int w){

  if(field[h][w] == '#') return 0;

  int ret = LEFT[h][w] + RIGHT[h][w] + UP[h][w] + DOWN[h][w] - 3;

  return ret;
}

int main(){
  // Input
  cin >> H >> W;

  rep(i, H){
    string str;
    cin >> str;
    rep(j, W){
      field[i][j] = str[j];
    }
  }

  init();

  int ans = 0;
  rep(i, H) rep(j, W){
    if(field[i][j] != '.') continue;
    ans = max(ans, calc(i, j));
  }

  cout << ans << endl;

  return 0;
}
