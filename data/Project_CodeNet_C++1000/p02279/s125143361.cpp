#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef complex<double> P;

struct Node {
  Node *parent;
  vector<Node*> childs;
  int num;
};

Node *root;

int main() {
  root = new Node;
  root->parent = root;
  int n;
  cin >> n;
  Node *nodes[n];
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node;
    nodes[i]->parent = root;
    nodes[i]->num = i;
  }

  for (int i = 0; i < n; i++) {
    int id, k;
    cin >> id >> k;

    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      nodes[id]->childs.push_back(nodes[c]);
      nodes[c]->parent = nodes[id];
    }
  }

  for (int i = 0; i < n; i++) {
    int parent = nodes[i]->parent == root ? -1 : nodes[i]->parent->num;
    int depth = 0;
    Node *p = nodes[i]->parent;
    while(p != root) {
      depth++;
      p = p->parent;
    }
    string type;
    if(nodes[i]->parent == root) type = "root";
    else if(nodes[i]->childs.size() == 0) type = "leaf";
    else type = "internal node";

    cout << "node " << i << ": ";
    cout << "parent = " << parent << ", ";
    cout << "depth = " << depth << ", ";
    cout << type << ", ";
    cout << "[";
    for (int j = 0; j < nodes[i]->childs.size(); j++) {
      cout << nodes[i]->childs[j]->num << (j+1 == nodes[i]->childs.size() ? "" : ", ");
    }
    cout << "]" << endl;
  }

  delete root;
  for (int i = 0; i < n; i++) {
    delete nodes[i];
  }
}