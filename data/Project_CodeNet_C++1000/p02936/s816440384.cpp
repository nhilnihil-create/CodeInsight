#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct node {
  ll cnt = 0;
  vector<int> nexts;
};

void hoge(vector<node> &nodes, int parent = 0, int pos = 1, int xsum = 0) {
  nodes[pos].cnt += xsum;
  for (int next : nodes[pos].nexts)
    if (parent != next)
      hoge(nodes, pos, next, nodes[pos].cnt);
}

int main() {
  ll n, q;
  cin >> n >> q;
  vector<node> nodes(n + 1);
  for (ll i = 1; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    nodes[a].nexts.push_back(b);
    nodes[b].nexts.push_back(a);
  }

  for (ll i = 0; i < q; ++i) {
    ll p, x;
    cin >> p >> x;
    nodes[p].cnt += x;
  }

  hoge(nodes);

  cout << nodes[1].cnt;
  for (ll i = 2; i <= n; ++i)
    cout << " " << nodes[i].cnt;
  cout << endl;
}