#include <iostream>
using namespace std;

const int MAX_N = 100000;

typedef struct {
  int parent, child, sibling;
} node;

int N;
node nodes[MAX_N];

void printChild(int id) {
  cout << ", [" << id;
  while (id != -1) {
    id = nodes[id].sibling;
    if (id == -1) break;
    cout << ", ";
    cout << id;
  }
  cout << ']';
}

int depth(int id) {
  int depth = 0;
  while (nodes[id].parent != -1) {
    id = nodes[id].parent;
    depth++;
  }
  return depth;
}

string type(int id) {
  if (nodes[id].parent == -1) return "root";
  else if (nodes[id].child == -1) return "leaf";
  else return "internal node";
}

void solve() {
  for (int i = 0; i < N; i++) {
    cout << "node " << i
         << ": parent = " << nodes[i].parent
         << ", depth = " << depth(i)
         << ", " << type(i);
    if (nodes[i].child == -1) cout << ", []";
    else printChild(nodes[i].child);

    cout << endl;
  }
}

int main() {
  int children[MAX_N];
  cin >> N;

  for (int i = 0; i < N; i++)
    nodes[i].parent = nodes[i].child = nodes[i].sibling = -1;

  for (int i = 0; i < N; i++) {
    int id; cin >> id;
    int degree_num; cin >> degree_num;
    for (int j = 0; j < degree_num; j++) {
      cin >> children[j];
      if (j == 0) nodes[id].child = children[j];
      if (j > 0) nodes[children[j-1]].sibling = children[j];
      nodes[children[j]].parent = id;
    }
  }
  solve();
}