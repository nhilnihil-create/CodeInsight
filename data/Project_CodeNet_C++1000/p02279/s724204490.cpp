
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define NIL -1

struct Node {
  int parent;  // 節点の親
  int left;    // 節点の一番左の子
  int right;   // 節点の右隣の兄弟
};


int getDepth(Node T[], int u) {
  int depth = 0;
  while (T[u].parent != NIL) {
    u = T[u].parent;
    depth ++;
  }
  return depth;
}

string getType(Node T[], int u) {
  if(T[u].parent == NIL) return "root";
  else if(T[u].left != NIL) return "internal node";
  else return "leaf";

}

void printChildren(Node T[], int u) {
  vector<int> printList;
  int c = T[u].left;
  while(c != NIL) {
    printList.push_back(c);
    c = T[c].right;
  }

  cout << "[";
  rep(i, printList.size()) {
    if(i == printList.size()-1) cout << printList[i];
    else cout << printList[i] << ", ";
  }
  cout << "]";
}

int main() {
  int n; cin>>n;
  Node T[n];

  rep(i, n) T[i].parent = T[i].right = T[i].left = NIL;

  rep(i, n) {
    int id, child;
    cin >> id >> child;

    int tmp;
    rep(j, child) {
      int cid; cin >> cid;
      if(j == 0) T[id].left = cid;
      else T[tmp].right = cid;  // 一個左の兄弟のrightを自分にする

      tmp = cid;
      T[cid].parent = id;
    }
  }

  //TODO: printChildren前でセグフォが起きている
  rep(i, n) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << getDepth(T, i) << ", ";
    cout << getType(T, i) << ", ";
    printChildren(T, i);
    cout << endl;
  }
  return 0;
}
