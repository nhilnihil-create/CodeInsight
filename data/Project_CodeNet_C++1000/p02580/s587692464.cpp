#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W, M;
  cin >> H >> W >> M;
  
  vector<int> hline(H,0);
  vector<int> wline(W,0);
  
  int h, w;
  set<pair<int,int>> target;
  for (int i = 0; i < M; i++) {
    cin >> h >> w;
    hline.at(h-1)++;
    wline.at(w-1)++;
    target.insert(make_pair(h-1,w-1));
  }
  
  int hmax = 0;
  for (int i = 0; i < H; i++) {
    hmax = max(hmax,hline.at(i));
  }
  
  vector<int> hmaxs(0);
  for (int i = 0; i < H; i++) {
    if (hmax == hline.at(i)) {
      hmaxs.push_back(i);
    }
  }
  
  int wmax = 0;
  for (int i = 0; i < W; i++) {
    wmax = max(wmax,wline.at(i));
  }
  
  vector<int> wmaxs(0);
  for (int i = 0; i < W; i++) {
    if (wmax == wline.at(i)) {
      wmaxs.push_back(i);
    }
  }
  
  int dup = 1;
  
  for (int i: hmaxs) {
    for (int j: wmaxs) {
      pair<int,int> p = make_pair(i,j);
      if (target.count(p) == 0) {
        dup = 0;
        goto end;
      }
    }
  }
  end:
  
  cout << hmax+wmax-dup << endl;
  
  return 0;
}