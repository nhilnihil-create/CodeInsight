#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

vector<int> ans;
int vis[10010] = {0};
int cc[10010];
vector<int> r[10010];

class priority {
  public:
    bool operator() (const pair<int,int> &x, const pair<int,int> &y) const {
      return x.second > y.second;
    }
};

void topo(int n) {
  priority_queue<pair<int,int>, vector<pair<int,int> >, priority> pq;
  for (int i = 0; i < n; i++) { 
    pq.push(make_pair(i, cc[i]));
  }
  while (!pq.empty()) {
    pair<int,int> now = pq.top();
    pq.pop();
    int no = now.first;
    int count = now.second;
    if (count != 0) break;
    if (vis[no]) continue;
    vis[no] = 1;
    ans.push_back(no);
    for (int i = 0; i < r[no].size(); i++) {
      int t = r[no][i];
      pq.push(make_pair(t, --cc[t]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    r[x].push_back(y);
    cc[y]++;
  }
  topo(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}