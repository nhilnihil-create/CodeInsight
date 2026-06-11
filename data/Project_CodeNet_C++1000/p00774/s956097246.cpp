#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define EPS 1e-10
#define INF 1000000000
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long ll;

void dropStones(vii &board) {
  for (int w = 0; w < 5; w++) {
    queue<int> que;
    for (int h = board.size() - 1; h > 0; h--){
      if (board[h][w] != 0) {
        que.push(board[h][w]);
        board[h][w] = 0;
      }
    }
    for (int h = board.size() - 1; h > 0; h--){
      if (que.empty()) {
        break;
      }
      board[h][w] = que.front();
      que.pop();
    }
  }
}

int calcPoints(vii &board) {
  int rep = 0;
  for (int h = 1; h < board.size(); h++) {
    int cnt = 1, p = board[h][2];
    vi tmp = board[h];
    tmp[2] = 0;
    if (p == 0) {
      continue;
    }
    for (int w = 3; w < board[0].size(); w++) {
      if (board[h][w] == p) {
        cnt++;
        tmp[w] = 0;
      } else {
        break;
      }
    }
    for (int w = 1; w >= 0; w--) {
      if (board[h][w] == p) {
        cnt++;
        tmp[w] = 0;
      } else {
        break;
      }
    }

    if (cnt >= 3) {
      rep += cnt * p;
      board[h] = tmp;
    }
  }
  if (rep == 0) {
    return 0;
  }
  dropStones(board);
  return rep + calcPoints(board);
}

int main() {
  int H;
  while (1) {
    cin >> H;
    if (H == 0) {
      break;
    }
    vii board(H + 1, vi(5, 0));
    for (int h = 1; h <= H; h++) {
      for (int w = 0; w < 5; w++) {
        cin >> board[h][w];
      }
    }
    cout << calcPoints(board) << endl;
  }
}