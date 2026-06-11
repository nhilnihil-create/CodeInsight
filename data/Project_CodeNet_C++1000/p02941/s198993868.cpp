#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
  int i;
  int v;

  Node(int i = -1, int v = -1) {
    this->i = i;
    this->v = v;
  }

  bool operator>(const Node &n) const {
    return v < n.v;
  }
};

int main() {
  int N;
  vector<int> A;
  vector<int> B;
  priority_queue <Node, vector<Node>, greater<Node> > pque;

  cin >> N;

  int a, b;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < N; ++i) {
    cin >> b;
    B.push_back(b);

    pque.push(Node(i, b));
  }

  ll ans = 0;

  while (!pque.empty()) {
    Node node = pque.top();
    pque.pop();

    if (node.v == A[node.i]) continue;

    int left = (node.i - 1 + N) % N;
    int right = (node.i + 1) % N;

    int d = B[left] + B[right];
    int r = (node.v - A[node.i]) / d;

    if (r == 0) {
      cout << -1 << endl;
      return 0;
    }

    ans += r;

    int nv = node.v - r * d;
    B[node.i] = nv;
    pque.push(Node(node.i, nv));
  }

  cout << ans << endl;

  return 0;
}
