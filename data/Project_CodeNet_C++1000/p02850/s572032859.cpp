#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N; cin >> N;
  vector<vector<pair<int, int>>> G(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b; a--; b--;
    G.at(a).push_back(make_pair(b, i));
    G.at(b).push_back(make_pair(a, i));
  }
  int max_deg = 0;
  REP(i, N) {
    max_deg = max((int)G.at(i).size(), max_deg);
  }
  // cout << max_deg << endl;

  vector<int> color(N - 1);

  vector<bool> seen(N, false);
  queue<pair<int, int>> todo;

  todo.push(make_pair(0, -1));
  seen[0] = true;
  while (!todo.empty()) {
    int here = todo.front().first;
    // cout << here << endl;
    int edge = todo.front().second;
    todo.pop();

    int color_num = 0;
    for (pair<int, int> pr: G.at(here)) {
      if (seen.at(pr.first) == false) { 
      seen.at(pr.first) = true;
      todo.push(pr);

      if (edge >= 0 && color_num == color.at(edge)) color_num++;
      color.at(pr.second) = color_num;
      color_num++;
      }
    }
  }

  cout << max_deg << endl;
  REP(i, N - 1) {
    cout << color.at(i) + 1 << endl;
  }
  
  return 0;
}