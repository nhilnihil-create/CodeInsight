#include <iostream>
using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

Node trees[MAX];
int depths[MAX];

void print(int id) {
  cout << "node " << id << ": ";
  cout << "parent = " << trees[id].parent << ", ";
  cout << "depth = " << depths[id] << ", ";

  if (trees[id].parent == NIL) {
    cout << "root, ";
  } else if (trees[id].left == NIL) {
    cout << "leaf, ";
  } else {
    cout << "internal node, ";
  }

  cout << "[";

  for (int i = 0, current = trees[id].left; current != NIL ; ++i, current = trees[current].right) {
    if (i != 0) {
      cout << ", ";
    }
    cout << current;
  }
  cout << "]" << endl;
}

void set_depths(int id, int depth) {
  depths[id] = depth;
  if (trees[id].right != NIL) {
    set_depths(trees[id].right, depth);
  }
  if (trees[id].left != NIL) {
    set_depths(trees[id].left, depth + 1);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int id, k;
    cin >> id >> k;
    int left;
    for (int j = 0; j < k; ++j) {
      int current;
      cin >> current;
      if (j == 0) {
        trees[id].left = current;
      } else {
        trees[left].right = current;
      }
      left = current;
      trees[current].parent = id;
    }
  }
  int root;
  for (int i = 0; i < n; ++i) {
    if (trees[i].parent == NIL) {
      root = i;
    }
  }

  set_depths(root, 0);

  for (int i = 0; i < n; ++i) {
    print(i);
  }

  return 0;
}

