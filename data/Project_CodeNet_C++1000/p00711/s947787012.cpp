#include <iostream>
#include <queue>
#include <set>
using namespace std;

const int MAX_SIZE = 20;
typedef pair<int, int> P;

int calc(char f[][MAX_SIZE + 1], queue<P> q, int W, int H) {
  set<P> s;
  while (q.size()) {
    P p = q.front();
    q.pop();
    s.insert(p);
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; ++k) {
      int i = p.first  + di[k];
      int j = p.second + dj[k];
      if (i >= 0 && j >= 0 && i < H && j < W && f[i][j] == '.') {
        pair<set<P>::iterator, bool> r = s.insert(P(i, j));
        if (r.second) q.push(*r.first);
      }
    }
  }
  return s.size();
}
int main() {
  int W, H;
  char f[MAX_SIZE + 1][MAX_SIZE + 1];
  while (true) {
    queue<P> q;
    cin >> W >> H;
    if (W == 0 && H == 0) break;
    for (int i = 0; i < H; ++i) {
      cin >> f[i];
      for (int j = 0; j < W; ++j) {
        if (f[i][j] == '@') {
          q.push(P(i, j));
        }
      }
    }
    cout << calc(f, q, W, H) << endl;
  }
}