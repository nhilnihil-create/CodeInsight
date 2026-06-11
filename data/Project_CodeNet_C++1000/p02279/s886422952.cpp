#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>

using namespace std;

void populate_depth(vector<class node *>&, int, int);

class node {
 public:
  vector<int> child_idxs;
  int id;
  int depth;
  explicit node(int id) :id{id} {}
};

int main() {
  int n; cin >> n;
  vector<node*> nodes(n);
  int id, k, cidx;
  for (int i = 0; i < n; ++i) nodes[i] = new node(i);

  for (int i = 0; i < n; ++i) {
    cin >> id >> k;
    nodes[id]->child_idxs = vector<int>();
    for (int ci = 0; ci < k; ++ci) {
      cin >> cidx;
      nodes[id]->child_idxs.push_back(cidx);
    }
  }

  vector<int> parents(n, -1);

  for (auto &v : nodes) {
    for (auto c : v->child_idxs) {
      parents[c] = v->id;
    }
  }

  int root_id = static_cast<int>(
      distance(parents.begin(), find(parents.begin(), parents.end(), -1))
      );

  populate_depth(nodes, root_id, 0);

  for (int i = 0; i < n; ++i) {
    cout << "node " << i << ": parent = " << parents[i]
      << ", depth = " << nodes[i]->depth << ", "
      << (parents[i] == -1 ? "root" :
          (nodes[i]->child_idxs.empty() ? "leaf" : "internal node"))
      << ", [";
    if (!(nodes[i]->child_idxs.empty())) {
      cout << nodes[i]->child_idxs.at(0);
      for (int ci = 1; ci < static_cast<int>(nodes[i]->child_idxs.size()); ++ci)
        cout << ", " << nodes[i]->child_idxs.at(ci);
    }
    cout << "]" << endl;
  }
}

void populate_depth(vector<node*> &nodes, int curr, int depth) {
  nodes[curr]->depth = depth;
  for (int cid : nodes[curr]->child_idxs)
    populate_depth(nodes, cid, depth + 1);
}
