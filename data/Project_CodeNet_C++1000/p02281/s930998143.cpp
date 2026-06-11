#include<iostream>
#include<cstring>
using namespace std;
int pro(int now);
int ino(int now);
int poo(int now);
typedef struct{
  int p,l,r;
}node;
int pr[100001],in[100001],po[100001];
node tree[100001];
int main(){
  cin.tie(0);
  memset(tree,-1,sizeof(tree));
  int n,v,r,l;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>v;
    cin>>r;
    cin>>l;
    tree[v].r=r;
    tree[v].l=l;
    if(tree[v].r!=-1) tree[r].p=v;
    if(tree[v].l!=-1) tree[l].p=v;
  }
  int rt;
  for(int i=0;i<n;++i){
    if(tree[i].p==-1){
    rt=i;
    }
  }
  cout<<"Preorder"<<endl;
  pro(rt);
  cout<<endl;
  cout<<"Inorder"<<endl;
  ino(rt);
  cout<<endl;
  cout<<"Postorder"<<endl;
  poo(rt);
  cout<<endl;
  return 0;
}
int pro(int now){
  if(now==-1)return 0;
  cout<<" "<<now;
  pro(tree[now].r);
  pro(tree[now].l);
}    
int ino(int now){
  if(now==-1) return 0;
  ino(tree[now].r);
  cout<<" "<<now;
  ino(tree[now].l);
}
int poo(int now){
  if(now==-1) return 0;
  poo(tree[now].r);
  poo(tree[now].l);
  cout<<" "<<now;
}