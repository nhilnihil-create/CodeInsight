#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

map< int, pair< int, int > > nodes;
map< int, pair< int, int > > parentsAndDepths;
int root = 0;

string nodeType(int id) {
  if (id == root)
    return "root";
  else if (nodes[id].first == -1)
    return "leaf";
  else
    return "internal node";
}

void getParentsAndDepths(void) {
  queue< int > fringe;
  fringe.push(root);
  parentsAndDepths[root] = pair< int, int > (-1, 0);
  while (!fringe.empty()) {
    int currentParent = fringe.front();
    fringe.pop();
    int currentNode = nodes[currentParent].first;
    while (currentNode != -1) {
      parentsAndDepths[currentNode] =
	pair< int, int > (currentParent, parentsAndDepths[currentParent].second+1);
      fringe.push(currentNode);
      currentNode = nodes[currentNode].second;
    }
  }
}

string children(int id) {
  ostringstream result;
  result << "[";
  int currentSibling = nodes[id].first;
  if (currentSibling != -1) {
    result << currentSibling;
    currentSibling = nodes[currentSibling].second;
    while (currentSibling != -1) {
      result << ", ";
      result << currentSibling;
      currentSibling = nodes[currentSibling].second;
    }
  }
  result << "]";
  return result.str();
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    nodes[i] = pair< int, int > (-1, -1);
  }
  vector< bool > isChild (n, false);
  for (int i = 0; i < n; i++) {
    int id, k, holder, sibling;
    cin >> id >> k;
    if (k) {
      cin >> holder;
      isChild[holder] = true;
      nodes[id].first = holder;
    }
    for (int j = 1; j < k; j++) {
      sibling = holder;
      cin >> holder;
      isChild[holder] = true;
      nodes[sibling].second = holder;
    }
  }
  for (int i = 0; i < n; i++)
    if (!isChild[i]) {
      root = i;
      break;
    }
  getParentsAndDepths();
  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << parentsAndDepths[i].first << ", ";
    cout << "depth = " << parentsAndDepths[i].second << ", ";
    cout << nodeType(i) << ", ";
    cout << children(i);
    cout << endl;
  }
  return 0;
}

