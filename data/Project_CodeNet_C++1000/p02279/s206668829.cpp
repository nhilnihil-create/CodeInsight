#include "bits/stdc++.h"
using namespace std;

struct Node{
  int parent,left,right;
};

Node T[100005];
int n,D[1000005];



void setDepth(int u, int p){
  D[u]=p;
  if(T[u].right!=-1){
    setDepth(T[u].right,p);
  }
  if(T[u].left!=-1){
    setDepth(T[u].left,p+1);
  }
}

int main(){
  int i=0,j=0,k=0,c=0,l=0,r=0,Tc=0;
  int id=0;
  cin>>n;
  for(i=0;i<n;i++){
    T[i].parent=T[i].left=T[i].right=-1;
  }
  for(i=0;i<n;i++){
    cin>>id>>k;
    for(j=0;j<k;j++){
      cin>>c;
      if(j==0)T[id].left=c;
      else T[l].right=c;
      l=c;
      T[c].parent=id;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==-1){
      r=i;
    }
  }
  setDepth(r,0);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,D[i]);
    if(T[i].parent==-1)cout<<"root, ";
    else if(T[i].left==-1)cout<<"leaf, ";
    else cout<<"internal node, ";
    cout<<"[";
    for(j=0,Tc=T[i].left;Tc!=-1;j++,Tc=T[Tc].right){
      //while(1){
      if(j)cout<<", ";
      cout<<Tc;
	//if(T[i].left==-1||T[i].left==T[T[i].left].right)break;
    }
    cout<<"]"<<endl;
    /*while(1){
      if(T[i].left==-1)break;
      
    }*/
  }
  return 0;
}

