#include <iostream>
using namespace std;
constexpr int MAX=100000;
constexpr int NIL=-1;

struct Node{
   int left;
   int right;
   int parent;
};

Node node[MAX];
int dep[MAX];

int setdepth(int u, int d){
   dep[u]=d;
   if(node[u].left!=NIL)
      setdepth(node[u].left, d+1);
   if(node[u].right!=NIL)
      setdepth(node[u].right, d);
}

int main(){
   int n, id, k, c, num;
   cin >> n;
   for(int i=0; i<n; i++) node[i].left=node[i].right=node[i].parent=NIL;
   for(int i=0; i<n; i++){
      cin >> id >> k;
      for(int i=0; i<k; i++){
         cin >> c;
         if(node[id].left==NIL)
            node[id].left=c;
         else 
            node[num].right=c;
         num = c;
         node[c].parent=id;
      }
   }

   int root;
   for(int i=0; i<n; i++){
      if(node[i].parent==NIL) root=i;
   }

   setdepth(root, 0);

   for(int i=0; i<n; i++){
      cout << "node " << i << ": ";
      cout << "parent = " << node[i].parent << ", ";
      cout << "depth = " << dep[i] << ", ";

      if(i==root) cout << "root, ";
      else if(node[i].left==NIL) cout << "leaf, ";
      else cout << "internal node, ";

      cout << "[";
      for(int j=0, c=node[i].left; c!=NIL; j++, c=node[c].right){
         if(j) cout << ", ";
         cout << c;
      }
      cout << "]" << endl;
   }

   return 0;
}
