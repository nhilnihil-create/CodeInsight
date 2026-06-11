#include <iostream>
#include <cstdlib>
#include <list>

const int MAX_N = 200000;

struct Node {
  int parent;
  std::list<int> *leaves;
};

int main(void) {
  int n = 0;
  struct Node *N[MAX_N];

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    struct Node *node = (struct Node *) std::malloc(sizeof(struct Node));

    node->parent = -1;
    node->leaves = new std::list<int>();
    
    N[i] = node;
  }

  for (int i = 0; i < n; i++) {
    int id = 0;
    int k = 0;

    std::cin >> id;
    std::cin >> k;
    
    for (int m = 0; m < k; m++) {
      int leaf = 0;
      
      std::cin >> leaf;
      
      N[id]->leaves->push_back(leaf);
      N[leaf]->parent = id;
    }
  }

  for (int i = 0; i < n; i++) {
    struct Node *node = N[i];
    
    std::cout << "node "<< i << ": ";
    std::cout << "parent = " << node->parent << ", ";

    int depth = 0;

    struct Node *p = node;

    while (p->parent >= 0) {
      p = N[p->parent];
      depth++;
    }
    
    std::cout << "depth = " << depth << ", ";

    if (node->parent < 0) {
      std::cout << "root";
    } else if ((node->parent >= 0) && (node->leaves->size() > 0)) {
      std::cout << "internal node";
    } else {
      std::cout << "leaf";
    }
    
    std::cout << ", [";
      
    for (std::list<int>::iterator iterator = node->leaves->begin(); iterator != node->leaves->end(); ++iterator) {
      std::cout << *iterator;

      ++iterator;

      if (iterator != node->leaves->end()) {
     	std::cout << ", ";
      }

      --iterator;
    }

    std::cout << "]" << std::endl;
  }
  
  return 0;
}