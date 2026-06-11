#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

#define MAX_N 100000

struct Node {
  int id;
  Node* parent;
  list<Node*> children;
};

void print_node(Node* node) {
  int parentId = -1;
  if (node->parent != NULL) {
    parentId = node->parent->id;
  }
  int depth = 0;
  for(Node* n = node; n->parent != NULL; n = n->parent) {
    depth++;
  }
  printf("node %d: parent = %d, depth = %d, ", node->id, parentId, depth);

  if(depth == 0) {
    printf("root, ");
  } else if(node->children.size() == 0) {
    printf("leaf, ");
  } else {
    printf("internal node, ");
  }

  printf("[");
  for(list<Node*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
    printf("%d", (*it)->id);
    it++;
    if(it != node->children.end()) {
      printf(", ");
    }
    it--;
  }
  printf("]\n");
}

int main() {
  Node nodes[MAX_N];
  nodes[0].parent = NULL;

  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int id, k;
    cin >> id >> k;
    nodes[id].id = id;

    int cid;
    for(int j=0; j<k; j++) {
      cin >> cid;
      nodes[cid].parent = &nodes[id];
      nodes[id].children.push_back(&nodes[cid]);
    }
  }

  for(int i=0; i<n; i++) {
    print_node(&nodes[i]);
  }
  return 0;
}