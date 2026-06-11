#include<bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node *next;
};
node L;
node* nil=&L;
int root;
node t[100000];

int main(){
  int n,par[100000];
  cin>>n;
  for(int i=0;i<n;i++)par[i]=-1;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b;
    node* pre=&t[a];
    for(int j=0;j<b;j++){
      cin>>c;
      node *p;
      p=(node *)malloc(sizeof(node));
      pre->next=p;
      pre->key=c;
      pre=p;
      par[c]=a;
    }
    pre->next=nil;
  }
  for(int i=0;i<n;i++)if(par[i]==-1)root=i;
  for(int i=0;i<n;i++){
    int dep=0;
    for(int j=par[i];j!=-1;j=par[j])dep++;
    cout<<"node "<<i<<": parent = "<<par[i]<<", depth = "<<dep<<", ";
    if(!dep)cout<<"root";
    else if(t[i].next==nil)cout<<"leaf";
    else cout<<"internal node";
    cout<<", [";
    for(node* j=&t[i];j->next!=nil;j=j->next){
      if(j!=&t[i])cout<<", ";
      cout<<j->key;
    }
    cout<<"]"<<endl;
  }
  return 0;
}