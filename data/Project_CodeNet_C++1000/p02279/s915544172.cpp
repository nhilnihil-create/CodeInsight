#include <iostream>
#include <vector>

struct Node
{
  // Given
  int num_of_child;
  std::vector<int> child;
  // Not given
  int parent;
  int depth;
  std::string type;
};

void init(Node tree[], int id, int parent, int parent_depth)
{
  tree[id].parent = parent;
  tree[id].depth = parent_depth + 1;

  if (tree[id].parent == -1)
  {
    tree[id].type = "root";
  }
  else if (tree[id].child.empty())
  {
    tree[id].type = "leaf";
  }
  else
  {
    tree[id].type = "internal node";
  }

  // Recursive call
  for (int i = 0; i < tree[id].num_of_child; ++i)
  {
    init(tree, tree[id].child[i], id, tree[id].depth);
  }
}

int main()
{
  int n;
  std::cin >> n;

  Node tree[n];
  int children[n] = { 0 };
  for (int i = 0; i < n; ++i)
  {
    int id;
    std::cin >> id;
    std::cin >> tree[id].num_of_child;

    for (int j = 0; j < tree[id].num_of_child; ++j)
    {
      int c;
      std::cin >> c;
      tree[id].child.push_back(c);
      children[c] = 1;
    }
  }

  int root_id = 0;
  while(children[root_id] == 1)
  {
    ++root_id;
  }

  init(tree, root_id, -1, -1);

  for (int i = 0; i < n; ++i)
  {
    std::cout << "node " << i
              << ": parent = " << tree[i].parent
              << ", depth = " << tree[i].depth
              << ", " << tree[i].type
              << ", [";
    for (int j = 0; j < tree[i].num_of_child; ++j)
    {
      if (j != 0) std::cout << ", ";
      std::cout << tree[i].child[j];
    }
    std::cout << ']' << std::endl;
  }

  return 0;
}

