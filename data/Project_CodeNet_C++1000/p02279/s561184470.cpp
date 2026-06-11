#include <iostream>
#include <vector>
using namespace std;

static int current_depth = 0;

struct Node{
  Node() : parent(-1), depth(-1) {}
  int parent, depth;
  vector<int> cld_;
};

void bfs(int pos, vector<Node>& tree){
  tree[pos].depth = current_depth;
  for(int i=0; i<tree[pos].cld_.size(); i++){
    current_depth++;
    bfs(tree[pos].cld_[i], tree);
    current_depth--;
  }
}

int main(){
  int n, id, k, cld;
  cin >> n;
  vector<Node> tree(n);
  for(int i=0; i<n; i++){
    cin >> id >> k;
    while(k--){
      cin >> cld;
      tree[id].cld_.push_back(cld);
    }
  }
  //set parent
  for(int i=0; i<n; i++){
    for(int j=0; j<tree[i].cld_.size(); j++)
      tree[tree[i].cld_[j]].parent = i;
  }
  //what is the root?
  int root;
  for(root=0; root<n; root++)
    if(tree[root].parent == -1)
      break;

  //set the depth
  bfs(root,tree);

  for(int i=0; i<tree.size(); i++){
    cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth << ", ";
    if(tree[i].parent == -1)
      cout << "root, [";
    else if(tree[i].cld_.size() == 0)
      cout << "leaf, [";
    else
      cout << "internal node, [";
    if(tree[i].cld_.size()!=0){
      for(int j=0; j<tree[i].cld_.size()-1; j++)
	cout << tree[i].cld_[j] << ", ";
      cout << tree[i].cld_[tree[i].cld_.size()-1];
    }
    cout << "]\n";
  }

  return 0;
}