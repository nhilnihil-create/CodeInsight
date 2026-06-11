#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

map<int, string> t;

enum NodeType{ROOT = 0,INTERNALNODE = 1,LEAF = 2};

struct type_name{
 map<int, string> type_map;
 type_name(){
  type_map[ROOT] = "root";
  type_map[INTERNALNODE] = "internal node";
  type_map[LEAF] = "leaf";
 }
};

struct Tree{
 int n;
 int root;
 struct type_name t;
 vector<int> parent;
 vector<int> depth;
 vector<int> type;
 vector< vector<int> > child;

 Tree(int n) : n(n){
  parent.reserve(n); parent.assign(n,-1);
  depth.reserve(n); depth.assign(n,0);
  type.reserve(n); type.assign(n,INTERNALNODE);
  child.reserve(n);
 }

 void SearchRoot(){
  for(int i = 0; i < parent.size(); i++){
   if(parent[i] == -1){
    root = i;
    type[i] = ROOT;
   }
  }  
 }

 void ComputeDepth(){
   queue<int> queue;

   queue.push(root);
   while( !queue.empty()){
    int key = queue.front();queue.pop();
    for(int i = 0; i < child[key].size(); i++){
     int buf = child[key][i];
     queue.push(buf);
     depth[buf] = depth[key] + 1;
    }
   }
 }

 void output(){
  for(int i = 0; i < n; i++){
   cout << "node " << i << ": parent = " << parent[i] << ", depth = " << depth[i] << ", " << t.type_map[type[i]] << ", [";
   for(int j = 0; j < child[i].size(); j++){
    cout << child[i][j] << (j+1 < child[i].size() ? ", " : "");
   }
   cout << "]" << '\n';
  }
 }
};

int main(){
 std::ios::sync_with_stdio(false);
 std::cin.tie(0); 

 int n = 0;
 cin >> n;
 
 Tree tree(n);
 
 for(int i = 0; i < n; i++){
   int node_num, child_num;
   cin >> node_num >> child_num;

   if(child_num == 0)
    tree.type[node_num] = LEAF;

   for( int j = 0; j < child_num; j++){
    int buf;
    cin >> buf;
    tree.child[node_num].push_back(buf);
    tree.parent[buf] = node_num;
   }
 }
 
 tree.SearchRoot();
 tree.ComputeDepth();
 tree.output();
 
 return 0;
}