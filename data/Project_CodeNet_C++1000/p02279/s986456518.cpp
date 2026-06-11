#include<iostream>
#define N 100000
using namespace std;

struct Node{
  int p,l,r;
};
Node t[N];

void print_node(int x){
  int s=t[x].l;
  if(s>=0) cout<<"["<<s;
  else if(s==-1){cout<<"[]";return;}
  while(1){
 if(t[s].r==-1) break;
 else cout<<", ";
 cout<<t[s].r;
 s=t[s].r;
  }
  cout<<"]";
}

int dep(int x){
  int cnt=0;
  if(t[x].p>=0) cnt=dep(t[x].p)+1;
  return cnt;
 }


int main(){
  int n,id,k,c;

  cin>>n;
  for(int i=0;i<n;i++)t[i].l=-1,t[i].p=-1,t[i].r=-1;

  for(int i=0;i<n;i++){
    cin>>id>>k;
    for(int j=0;j<k;j++){
      int befc=c;
      cin>>c;
      t[c].p=id;
      if(j>0)t[befc].r=c;
      else t[id].l=c;
    }
  }
   for(int i=0;i<n;i++){
cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = ";
 cout<<dep(i)<<", ";
  if(t[i].l>=0 && t[i].p!=-1) cout<<"internal node, ";
  else if(t[i].p==-1) cout<<"root, ";
  else cout<<"leaf, ";
  print_node(i);
  cout<<endl;
  }


  return 0;
}