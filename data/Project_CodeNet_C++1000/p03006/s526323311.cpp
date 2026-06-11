#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  int N; cin >> N;

  vector < pair<int, int> > XY(N);
  for (int i = 0; i < N; i++){
    int X, Y; cin >> X >> Y;
    XY[i].first = X;
    XY[i].second = Y;
  }
  sort(XY.begin(), XY.end());

  vector < pair<int, int> > PQ;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      int P = XY[i].first - XY[j].first;
      int Q = XY[i].second - XY[j].second;
      PQ.push_back(make_pair(P, Q));
    }
  }

  int ans = N;
  for (int i = 0; i < PQ.size(); i++){
    int P = PQ[i].first, Q = PQ[i].second;
    int cnt = N;

    vector <bool> visited(N);
    visited[0] = true;

    queue <int> que; que.push(0);

    while (!que.empty()){
      int now = que.front(); que.pop();
      int X = XY[now].first, Y = XY[now].second;

      pair <int, int> next = make_pair(X - P, Y - Q);

      for (int j = 0; j < N; j++){
        if (XY[j] == next && visited[j] == false){
          visited[j] = true;
          que.push(j);
          cnt--;
          break;
        }
      }
      
      if (que.empty()){
        for (int j = 0; j < N; j++){
          if (visited[j] == false){
            que.push(j);
            visited[j] = true;
            break;
          }
        }
      }
    }

    if (ans > cnt) ans = cnt;
  }
  
  cout << ans << endl;


  return 0;
}
