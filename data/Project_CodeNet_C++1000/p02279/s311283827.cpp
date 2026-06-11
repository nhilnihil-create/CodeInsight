#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Tree
{
private:
  struct Node
  {
    int id;
    int parent;
    vector<int> children;
  };
public:
  int size;
  vector<Node> nodes;
  Tree(int n)
  {
    size = n;
    nodes.resize(n);
    for(int i = 0; i < n; i++)
    {
      nodes[i].id = i;
      nodes[i].parent = i;
    }
  }
  void addChild(int id,int x)
  {
    nodes[id].children.push_back(x);
    nodes[x].parent = id;
  }
  bool isRoot(int id)
  {
    return id == nodes[id].parent;
  }
  int depth(int id)
  {
    int x = id;
    int cnt = 0;
    while(x != nodes[x].parent)
    {
      x = nodes[x].parent;
      cnt++;
    }
    return cnt;
  }
  char* printType(int id)
  {
    if(id == nodes[id].parent)
      return (char *)"root";
    else if(nodes[id].children.size() == 0)
      return (char *)"leaf";
    else return (char *)"internal node";
  }
  void printInfo(int id)
  {
    printf("node %d: ",id);
    printf("parent = %d, ",isRoot(id)?-1:nodes[id].parent);
    printf("depth = %d, ",depth(id));
    printf("%s, ", printType(id));
    printf("[");
    for(int i = 0; i < nodes[id].children.size(); i++)
    {
      printf("%d",nodes[id].children[i]);
      if(i != nodes[id].children.size()-1)
        printf(", ");
    }
    printf("]\n");
  }
};

int main()
{
  int n;
  cin >> n;
  Tree tree(n);
  for(int i = 0; i < n; i++)
  {
    int id, k;
    cin >> id >> k;
    for(int j = 0; j < k; j++)
    {
      int child;
      cin >> child;
      tree.addChild(id,child);
    }
  }
  for(int i = 0; i < n; i++) tree.printInfo(i);
  return 0;
}