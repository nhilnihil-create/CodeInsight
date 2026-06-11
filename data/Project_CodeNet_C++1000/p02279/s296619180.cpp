#include<iostream>
using namespace std;
#define MAX 1000000
typedef struct{ 
  int p, l, r;
}Node;
Node t[1000000];
int count,h,d[1000000];
void b(int); 
 
int main(){
  int n,id,k,c,l,r;
  cin>>n;
  for(int i=0;i<n;i++) {
    t[i].p=-1;
    t[i].l=-1;
    t[i].r=-1;
  }  
  for(int i=0;i<n;i++){
    cin>>id>>k;
    for(int j=0;j<k;j++){
      cin>>c;
      t[c].p=id;
      if(j==0)t[id].l=c;
      else t[r].r=c;
      r=c;
    }
  }
 
  for(int i=0;i<n;i++){
    b(i);
    d[i]=count;
  }
  for(int i=0;i<n;i++){
    if(t[i].p==-1)
    cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<d[i]<<", root, ";  
    else if(t[i].l==-1)
    cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<d[i]<<", leaf, ";         
    else
      cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<d[i]<<", internal node, ";
    int j=i;
    cout<<'[';
    if(t[j].l!=-1){
      cout<<t[j].l;
      if(t[t[j].l].r==-1) cout<<']'<<endl;
      else cout<< ", ";
        
      j=t[j].l;
      while(t[j].r!=-1){
    cout<<t[j].r;
      if(t[t[j].r].r==-1)cout<<']'<<endl;
      else cout<<", ";
      j=t[j].r;
      }
    }
    else cout<<']'<<endl; 
  }
  return 0;
}
 
void b(int x){
  count=0;
  while(t[x].p>=0){
    x=t[x].p; 
    count++;
  }
}

