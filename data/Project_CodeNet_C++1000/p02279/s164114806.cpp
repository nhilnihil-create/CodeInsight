#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define max 100001
struct node {int p,l,r;};
struct node t[max];
int d[max];
void getdepth(int i,int j){
  d[i]=j;
  if(t[i].r!=-1)getdepth(t[i].r,j);
  if(t[i].l!=-1)getdepth(t[i].l,j+1);
}

int main(){
  int n,id,k,m,tmp1,tmp2,j;
  cin>>n;
  for(int i=0;i<n;i++)
    t[i].p=t[i].l=t[i].r=-1;
  for(int i=0;i<n;i++){
    cin>>id>>k;
    if(k>0){
      cin>>tmp1;
      t[id].l=tmp1;
      t[tmp1].p=id;
    }
    for(int j=1;j<k;j++){
      cin>>tmp2;
      t[tmp1].r=tmp2;
      tmp1=tmp2;
      t[tmp1].p=id;
      }
    /*for(int j=0;j<k;j++){
      cin>>tmp1;
      if(j==0)t[id].l=tmp1;
      else t[tmp2].r=tmp1;
      tmp2=tmp1;
      t[tmp1].p=id;
      }*/
  }
  for(int i=0;i<n;i++){
    if(t[i].p==-1)m=i;
  }
  getdepth(m,0);
  for(int i=0;i<n;i++){
    cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<d[i]<<", ";
    if(t[i].p==-1)cout<<"root";
    else if(t[i].l==-1)cout<<"leaf";
    else cout<<"internal node";
    cout<<", [";
    if((t[i].l)!=-1){
      cout<<t[i].l;
    for(tmp1=t[t[i].l].r;tmp1!=-1;tmp1=t[tmp1].r){
      cout<<", "<<tmp1;
    }
    }
    cout<<"]"<<endl;
  }
  return 0;
}

