#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k)
  {
    return(-data[find(k)]);
  }
};


int main() {
    int N; cin >> N;
    vector<pair<int, int>> balls(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> balls[i].first;
        cin >> balls[i].second;
    }
    set<pair<int, int>> pq;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i <= N; i++) pq.insert({balls[i].first - balls[j].first, balls[i].second - balls[j].second});
    }
    int ans = 100000;
    for (auto k : pq) {
        UnionFind uf = UnionFind(N+1);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if ((k.first == balls[i].first - balls[j].first && k.second == balls[i].second - balls[j].second)
                 || (k.first == balls[j].first - balls[i].first && k.second == balls[j].second - balls[i].second)) {
                     uf.unite(i, j);
                 }
            }
        }
        set<int> roots;
        for (int i = 1; i <= N; i++) {
            roots.insert(uf.find(i));
        }
        ans = min(ans, (int)roots.size());
    }
    cout << ans << endl;
}
