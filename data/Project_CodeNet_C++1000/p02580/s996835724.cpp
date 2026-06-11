#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> A(H), B(W);
  set<pair<int, int>> object;
  for(int i = 0; i < M; i++) {
    int h, w;
    cin >> h >> w;
    A.at(h - 1)++;
    B.at(w - 1)++;
    object.insert(make_pair(h - 1, w - 1));
  }
  int maxa = 0;
  int maxb = 0;
  for(int i = 0; i < H; i++) {
    maxa = max(maxa, A.at(i));
  }
  for(int i = 0; i < W; i++) {
    maxb = max(maxb, B.at(i));
  }
  vector<int> vecA, vecB;
  for(int i = 0; i < H; i++) {
    if(A.at(i) == maxa) {
      vecA.push_back(i);
    }
  }
  for(int i = 0; i < W; i++) {
    if(B.at(i) == maxb) {
      vecB.push_back(i);
    }
  }
  int64_t la = vecA.size();
  int64_t lb = vecB.size();
  if(la * lb > M) {
    cout << maxa + maxb << endl;
  }
  else {
    for(int i = 0; i < vecA.size(); i++) {
      for(int j = 0; j < vecB.size(); j++) {
        if(!object.count(make_pair(vecA.at(i), vecB.at(j)))) {
          cout << maxa + maxb << endl;
          return 0;
        }
      }
    }
    cout << maxa + maxb - 1 << endl;
  }
}