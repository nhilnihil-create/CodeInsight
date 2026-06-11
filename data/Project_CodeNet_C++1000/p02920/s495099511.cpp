#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
  int v;
  int gene;

  Node(int v = -1, int gene = -1) {
    this->v = v;
    this->gene = gene;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> S;

  int s;
  for (int i = 0; i < pow(2, N); ++i) {
    cin >> s;
    S.push_back(s);
  }

  sort(S.begin(), S.end());

  queue<Node> que;
  que.push(Node(S.back(), 0));
  S.erase(S.begin() + S.size() - 1);

  while (!que.empty()) {
    Node node = que.front();
    que.pop();

    // fprintf(stderr, "parent: %d, gene: %d, S = %d\n", node.v, node.gene, (int) S.size());

    int L = S.size();
    int idx = lower_bound(S.begin(), S.end(), node.v) - S.begin();

    if (idx == L) {
      idx = L - 1;
    } else {
      idx = max(0, idx - 1);
    }

    // fprintf(stderr, "idx = %d\n", idx);

    int child = S[idx];

    if (node.v <= child) {
      cout << "No" << endl;
      return 0;
    }

    S.erase(S.begin() + idx);

    if (node.gene + 1 < N) {
      que.push(Node(node.v, node.gene + 1));
      que.push(Node(child, node.gene + 1));
    }
  }

  cout << "Yes" << endl;

  return 0;
}
