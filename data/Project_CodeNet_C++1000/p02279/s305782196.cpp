#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include <math.h>
#include<algorithm>
using namespace std;
#define MAX 100000
#define NIL -1

struct node{
  int p,l,r;
};

node A[MAX];

int D[MAX];

void setDepth(int v,int d){
  if(v==NIL) return;
  D[v]=d;
  setDepth(A[v].l,d+1);
  setDepth(A[v].r,d);
}



int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    A[i].p=A[i].l=A[i].r=NIL;
  }
  int v,k,temp,l,root;
  for(int i=0;i<n;i++){
    cin>>v>>k;
    for(int j=0;j<k;j++){
      scanf("%d",&temp);
      if(j==0) A[v].l=temp;
      else A[l].r=temp;
      l=temp;
      A[l].p=v;
    }
  }
  for(int i=0;i<n;i++){
    if(A[i].p==NIL) root=i;
  }
  setDepth(root,0);
  for(int i=0;i<n;i++){
    cout<<"node "<<i<<": parent = "<<A[i].p<<", depth = "<<D[i]<<", ";
    if(D[i]==0) cout<<"root";
    else if(A[i].l==NIL) cout<<"leaf";
    else cout<<"internal node";
    cout<<", [";
    v=A[i].l;
    int count=0;
    while(v!=NIL){
      if(count) cout<<", ";
      cout<<v;
      count++;
      v=A[v].r;
    }
    cout<<"]"<<endl;
  }
}

