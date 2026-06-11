#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
#include <queue>
#include <list>
using namespace std;


//?°???\???????????????public?????????
class Node {
public:
  int id;
  int parent;
  int depth;
  string type;
  int degree;
  vector<int> c;
public:

  Node(int id, vector<int> c): id(id), c(c)
  {
    depth = degree = parent = -1;
  }
  void print();
};

void Node::print(){
  if(parent == -1)  type = "root";
  else if(!c.size()) type = "leaf";
  else              type = "internal node";
  printf("node %d: parent = %d, depth = %d, %s, [", id, parent, depth, type.c_str());
  for(int i=0;i<(int)c.size();i++){
    printf("%d", c[i]);
    if(i != (int)c.size()-1){
      printf(", ");
    }
  }
  printf("]\n");
}

int search(vector<Node> &v, int id, int depth){
  v[id].depth = depth;
  for(int i=0;i<v[id].c.size();i++){
    search(v, v[id].c[i], depth+1);
  }
}

bool asc(const Node &right, const Node &left){return right.id < left.id;}

int main(void){
  int n;
  cin >> n;
  vector<Node> nodes;

  //??\?????¨
  for(int i=0;i<n;i++){
    int id, t; cin >> id >> t;
    vector<int> v(t);
    for(int j=0;j<t;j++)
      cin >> v[j];
    Node node(id, v);
    nodes.push_back(node);
  }

  sort(nodes.begin(), nodes.end(), asc);

  //????????¨
  for(int i=0;i<n;i++){
    for(int j=0;j<nodes[i].c.size();j++){
      nodes[nodes[i].c[j]].parent = nodes[i].id;
    }
  }
  for(int i=0;i<n;i++){
    if(nodes[i].parent == -1){
      search(nodes, i, 0);
    }
  }

  //????????¨
  for(int i=0;i<n;i++){
    nodes[i].print();
  }

  return 0;
}