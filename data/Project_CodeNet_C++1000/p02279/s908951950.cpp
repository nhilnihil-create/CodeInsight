#include<bits/stdc++.h>
using namespace std;


typedef struct{

  int parent;
  int depth;
  int type;    //0:root , 1:node , 2:leaf
  vector<int> child;

}node_t;

vector <node_t> tree; 


void Depth(int num, int d){

  tree[num].depth = d;

  if(tree[num].child.size()==0)return ;

  for(int i=0; i<(int)tree[num].child.size(); i++)
    Depth(tree[num].child[i] , d+1);

}


int main(){

  int n;
  int num , child , k;


  cin >> n;
  tree.resize(n);


  for(int i=0; i<n; i++){
    tree[i].child.resize(0);
    tree[i].type = 2;
    tree[i].parent = -1;
  }



  for(int i=0; i<n; i++){

    cin >> num >> k;
    if(k!=0)tree[num].type = 1;

    for(int j=0; j<k; j++){
      cin >> child;
      tree[num].child.push_back(child);
      tree[child].parent = num;
    }

  }


  for(int i=0; i<n; i++){
    if(tree[i].parent == -1){
      tree[i].type = tree[i].depth = 0; 
      Depth(i,0);
      break;
    }
  }



  for(int i=0; i<n; i++){

    cout << "node " << i << ": parent = " << tree[i].parent
	 << ", depth = " << tree[i].depth << ", ";

    if(tree[i].type == 0)cout << "root, ";
    else if(tree[i].type == 1)cout << "internal node, ";
    else cout << "leaf, ";

    cout << '[';
    if(tree[i].child.size()>0){
      cout << tree[i].child[0] ;
      for(int j=1; j<(int)tree[i].child.size(); j++)
	cout << ", " << tree[i].child[j];
    }
    cout << ']' << endl;


  }
  

  return 0;
}