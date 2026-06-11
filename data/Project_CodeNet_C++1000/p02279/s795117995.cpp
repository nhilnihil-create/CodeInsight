#define MYDEBUG
//
#include <bits/stdc++.h>
#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
using namespace std;

typedef struct Node {
  int parent, left, right;
} Node;

static const int NMAX = 100000;
static const int NIL = -1;
Node T[NMAX];
int n, D[NMAX];
static const string ROOT = "root";
static const string INTERNAL = "internal node";
static const string LEAF = "leaf";

//頂点番号idに深さdepthを記録
void setDepth(int id, int depth) {
  D[id] = depth;
  if (T[id].right != NIL) {
    setDepth(T[id].right, depth);
  }
  if (T[id].left != NIL) {
    setDepth(T[id].left, depth + 1);
  }
}

//頂点番号idのすべての子を表示
void printChildren(int id) {
  cout << "[";
  int cid = T[id].left;
  while (cid != NIL) {
    if (cid != T[id].left) {
      cout << ", ";
    }
    cout << cid;
    cid = T[cid].right;
  }
  cout << "]";
}

void printNode(int id) {
  if (id == NIL) {
    return;
  }
  printf("node %d: parent = %d, depth = %d, ", id, T[id].parent, D[id]);
  string nodeType = INTERNAL;
  if (T[id].parent == NIL) {
    nodeType = ROOT;
  } else if (T[id].left == NIL) {
    nodeType = LEAF;
  }
  printf("%s, ", nodeType.c_str());
  printChildren(id);
  printf("\n");
}

int main() {
  cin >> n;
  rep(i,0,NMAX)
  {
    T[i].parent = T[i].left = T[i].right = NIL;
    D[i] = 0;
  }
  rep(i,0,n)
  {
    int id, k;
    cin >> id >> k;
    int lastChild = NIL;
    rep(j,0,k)
    {
      int c;
      cin >> c;
      T[c].parent = id;
      if (T[id].left == NIL) {
        T[id].left = c;
      }
      if (lastChild != NIL) {
        T[lastChild].right = c;
      }
      lastChild = c;
    }
  }
  int root = 0;
  rep(i,1,n)
  {
    if (T[i].parent == NIL) {
      root = i; //頂点番号0が根とは限らない
    }
  }
  setDepth(root, 0);
  rep(i,0,n)
  {
    printNode(i);
  }
}

