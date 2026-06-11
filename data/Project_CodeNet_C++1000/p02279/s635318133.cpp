#include<iostream>
using namespace std;
#define MAX 100005
#define HN -1

struct Node{
  int p,l,r;
};

Node Ta[MAX];
int num,Da[MAX];

void express(int d){
  int i,o;
  cout << "node "<< d <<": ";
  cout << "parent = "<< Ta[d].p << ", ";
  cout << "depth = "<<Da[d] <<", ";

  if(Ta[d].p == HN){
    cout << "root, ";
  }
    else if(Ta[d].l == HN){
      cout << "leaf, ";
    }
    else cout << "internal node, ";

  cout << "[";

  for(i=0,o=Ta[d].l;o!=HN;i++,o=Ta[o].r){
    if(i){
      cout<<", ";

    }
    cout << o;
  }
  cout <<"]"<<endl;
}

int jug(int u,int p){
  Da[u] =p;
  if(Ta[u].r != HN){
    jug(Ta[u].r,p);
  }
  if(Ta[u].l != HN){
    jug(Ta[u].l,p+1);
  }
}

int main(){
  int i,j,d,vi,ci,l,r;
  cin >> num;
  for(i=0;i<num;i++){
    Ta[i].p=Ta[i].l=Ta[i].r=HN;
  }
  for(i=0;i<num;i++){
    cin >> vi >>d;
    for(j=0;j<d;j++){
      cin>>ci;
      if(j==0){
	Ta[vi].l =ci;
      }
      else Ta[l].r=ci;
      l=ci;
      Ta[ci].p=vi;
    }
  }
  for(i=0;i<num;i++){
    if(Ta[i].p ==HN){
      r=i;
    }
  }

  jug(r,0);

  for(i=0;i<num;i++){
    express(i);
  }

  return 0;
}

