#include <iostream>
#include <array>
#include <string>

const int NIL = -1;
struct node
{
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

using binaryTree =  std::array<node, 25>;

std::string getType(node n)
{
  if (n.parent == NIL) return "root";
  else if (n.left == NIL && n.right == NIL)
    return "leaf";
  else
    return "internal node";
}


int getRootID(binaryTree tree, int n)
{
  for (int i=0; i<n; ++i)
    {
      if (getType(tree[i]) == "root")
        {
          return i;
        }
    }
  return NIL;
}

auto print = [](auto x){std::cout << " " << x;};

void preOrder(binaryTree tree, int root_id)
{
  print(root_id);
  if (tree[root_id].left != NIL)
    preOrder(tree, tree[root_id].left);
  if (tree[root_id].right != NIL)
    preOrder(tree, tree[root_id].right);
}

void inOrder(binaryTree tree, int root_id)
{
  if (tree[root_id].left != NIL)
    inOrder(tree, tree[root_id].left);
  print(root_id);
  if (tree[root_id].right != NIL)
    inOrder(tree, tree[root_id].right);
}

void postOrder(binaryTree tree, int root_id)
{
  if (tree[root_id].left != NIL)
    postOrder(tree, tree[root_id].left);
  if (tree[root_id].right != NIL)
    postOrder(tree, tree[root_id].right);
  print(root_id);
}


int main ()
{
  int n;
  std::cin >> n;

  binaryTree tree;
  for (int i=0; i<n; ++i)
    {
      int id, left, right;
      std::cin >> id >> left >> right;
      tree[id].left = left;
      tree[id].right = right;
      tree[left].parent = id;
      tree[right].parent = id;
    }

  auto root_id = getRootID(tree, n);

  std::cout << "Preorder\n";
  preOrder(tree, root_id);
  std::cout << std::endl;

  std::cout << "Inorder\n";
  inOrder(tree, root_id);
  std::cout << std::endl;

  std::cout << "Postorder\n";
  postOrder(tree, root_id);
  std::cout << std::endl;


}

