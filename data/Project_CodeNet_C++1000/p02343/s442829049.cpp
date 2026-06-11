#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static const int MAX = 200000;

void trace(int data[], int n) {
  cout << data[0];
  for (int i = 1; i < n; i++) {
    cout << " " << data[i];
  }
  cout << endl;
}

class Dtree {
public:
  vector<int> rank, parent;

  Dtree(int size) {
    rank.resize(size, 0);
    parent.resize(size, 0);
    for (int i = 0; i < parent.size(); i++)
      parent[i] = i;
    for (int i = 0; i < rank.size(); i++)
      rank[i] = 0;
  }
  int unite(int x, int y) {
    while (1) {
      int pre = parent[y];
      parent[y] = label(x);
      if (y == pre)
        break;
      y = pre;
    }
  }
  int same(int x, int y) { return label(x) == label(y); }
  int label(int x) {
    while (x != parent[x]) {
      x = parent[x];
    }
    return x;
  }
};

int main() {
  int data[MAX];
  int n, nquery;
  cin >> n;
  cin >> nquery;
  Dtree dt = Dtree(n);
  for (int i = 0; i < nquery; i++) {
    int x, y, command;
    cin >> command >> x >> y;
    if (command == 0) {
      dt.unite(x, y);
    } else if (command == 1) {
      cout << (dt.same(x, y) ? 1 : 0) << endl;
    }
  }
}