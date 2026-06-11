#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_N 100000
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};

void print_node(Node nodes[], int i, int depth[]) {
  printf("node %d: parent = %d, depth = %d, ", i, nodes[i].parent, depth[i]);

  if(nodes[i].parent == NIL) {
    printf("root, ");
  } else if(nodes[i].left == NIL) {
    printf("leaf, []");
    return;
  } else {
    printf("internal node, ");
  }

  printf("[");
  for(int n=nodes[i].left; n!=NIL; n=nodes[n].right) {
    printf("%d", n);
    if(nodes[n].right != NIL) {
      printf(", ");
    }
  }
  printf("]");
}

void walk_depth(Node nodes[], int depth[], int p, int d) {
  depth[p] = d;
  for(int n=nodes[p].left; n!=NIL; n=nodes[n].right) {
    walk_depth(nodes, depth, n, d+1);
  }
}

int main() {
  Node nodes[MAX_N];
  int depth[MAX_N];
  int cs[MAX_N];


  int n;
  cin >> n;

  for(int i=0; i<n; i++) {
    nodes[i].parent = NIL;
  }

  for(int i=0; i<n; i++) {
    int id, k;
    cin >> id >> k;

    cs[0] = NIL;
    for(int j=0; j<k; j++) {
      cin >> cs[j];
      nodes[cs[j]].parent = id;
    }
    cs[k] = NIL;
    for(int j=0; j<k; j++) {
      nodes[cs[j]].right = cs[j+1];
    }
    nodes[id].left = cs[0];
  }

  int root = 0;
  for(int i=0; i<n; i++) {
    if(nodes[i].parent == NIL)
      root = i;
  }
  walk_depth(nodes, depth, root, 0);

  for(int i=0; i<n; i++) {
    print_node(nodes, i, depth);
    printf("\n");
  }
}