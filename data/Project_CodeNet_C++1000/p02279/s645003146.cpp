#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
map <int ,int> mpa,mpb;
#define MAX 100005
#define NIL -1

struct Node {int p,l,r;};

Node T[MAX];
int n, D[MAX];

void print(int u){
  int i ,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";
  if(T[u].p==NIL) cout << "root, ";
  else if(T[u].l==NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int rec(int u,int p){
  D[u]=p;
  if(T[u].r !=NIL) rec(T[u].r,p);//深さを入れてく
  if(T[u].l !=NIL) rec(T[u].l,p+1);
}

int main(){
  int i,j,d,v,c,l,r;
  cin >> n;
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r =NIL;//初期化

  for(i=0;i<n;i++){
    cin >> v >> d;
    for(j=0;j<d;j++){
      cin >> c;
      if(j==0) T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL) r=i;
  }
  rec(r,0);
  for(i=0;i<n;i++) print(i);

  return 0;
}
