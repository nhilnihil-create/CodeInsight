#include <iostream>
using namespace std;

typedef struct{
  int root,child,sibling;
}Node;

int getParent(Node *T,int id){
  return T[id].root;
}

int getDepth(Node *T,int id){
  int i=id,count=0;
  while(T[i].root!=-1){
    i=T[i].root;
    count++;
  }
  return count;
}

int getType(Node *T,int id){
  if (T[id].root==-1)return 0;
  if (T[id].child==-1)return 2;
  return 1;
}

int getChild(Node *T,int id,int *childs){
  int i=0;
  int child=T[id].child;
  if (child==-1)return 0;
  childs[i++]=child;
  while (T[child].sibling!=-1){
    child=T[child].sibling;
    childs[i++]=child;
  }
  return i;
}

int main(){
  Node T[100000];
  int chl[100000];
  int n,id,cn,cid,pcid;
  char *types[]={(char*)"root",(char*)"internal node",(char*)"leaf"};

  for (int i=0;i<100000;i++){
    T[i].root=-1;
    T[i].child=-1;
    T[i].sibling=-1;
  }
  cin >> n;
  for (int i=0;i<n;i++){
    cin >> id >> cn;
    pcid=-1;
    for (int j=0;j<cn;j++){
      cin >> cid;
      if (T[id].child==-1) T[id].child=cid;
      T[cid].root=id;
      if (pcid!=-1)T[pcid].sibling=cid;
      pcid=cid;
    }
  }
  for (int i=0;i<n;i++){
    //    printf("node 0: parent = -1, depth = 0, root, [1, 4, 10]");
    cout <<"node "<< i << ": ";
    cout <<"parent = "<<getParent(T,i)<<", ";
    cout <<"depth = "<<getDepth(T,i)<<", ";
    cout <<types[getType(T,i)] <<", [";
    cn=getChild(T,i,chl);
    for(int j=0;j<cn;j++){
      cout <<chl[j];
      if (j<cn-1)cout <<", ";
    }
    cout <<"]" << endl;
  }

  return 0;
}