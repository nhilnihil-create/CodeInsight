/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp
*/
//根付き木
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Node{
  //int num; //ノード番号
  int parent; //親
  vector<int> children;
  string type;
}Node;

Node tree[100000];

int dep(int k){
  int depth=0;
  int x=tree[k].parent;
  for(int i=0;i<100000;i++){
    if(x==-1) return depth;
    else{
      x=tree[x].parent;
      depth++;
    }
  }
}
void output(int N){
  for(int i=0;i<N;i++){
    cout<<"node "<<i<<": "
    <<"parent = "<<tree[i].parent<<", "
    <<"depth = "<<dep(i)<<", "
    <<tree[i].type<<", "<<"[";
    for(int j=0;j<tree[i].children.size();j++){
      if(j)cout<<", ";
      cout<<tree[i].children[j];
    }
    cout<<"]"<<"\n";
  }
}
void makeTree(int N){
  int k,nodenum,child;
  for(int i=0;i<N;i++){
    cin>>nodenum>>k;
    for(int j=0;j<k;j++){
      cin>>child;
      tree[nodenum].children.push_back(child);
      tree[child].parent=nodenum;
    }
  }
  if(N==1) tree[0].type="root";else
  for(int i=0;i<N;i++){
    if(tree[i].parent==-1) tree[i].type="root";
    if(tree[i].children.size()==0) tree[i].type="leaf";
    }
}
int main(){
  int N;
  cin>>N;
  //初期化
  for(int i=0;i<N;i++){tree[i].parent=-1;tree[i].type="internal node";}
  makeTree(N);
  output(N);
}

