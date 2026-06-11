#include <bits/stdc++.h>
using namespace std;
int par[100000];
struct node{
  node *next;
  int key;
};
 
node *head[100000];

void mk_node(int key,node *next,node *prev){
  node *n=(node *)malloc(sizeof(node));
  n->key=key;
  n->next=next;
  prev->next=n;
}
 
void insert(int x,int i){mk_node(x,head[i]->next,head[i]);}

void init(int n){
    for(int i=0;i<n;i++){
    par[i]=-1;
    head[i]=(node *)malloc(sizeof(node *));
    head[i]->next=head[i];
    head[i]->key=-1;
  }
 
}

int get_dep(int x,int dep){
  if(x==-1) return dep;
  return get_dep(par[x],dep+1);
}

void print_list(int x){
  int a[100000];

  node *i=head[x]->next;
  int idx=0;
  while(i!=head[x])a[idx++]=i->key,i=i->next;
  
  cout <<"[";
  for(int j=idx-1;j>=1;j--)cout << a[j]<<", ";
  if(idx) cout <<a[0];
  cout <<"]"<<endl;
}

int main(){
  int n;
  cin>>n;
  
  init(n);
  for(int i=0,a,b;i<n;i++){
    cin>>a>>b;
    for(int j=0,c;j<b;j++){
      cin>>c;
      insert(c,a);
      par[c]=a;
    }
    
  }

  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,par[i],get_dep(i,-1));
    if(par[i]==-1) cout <<"root, ";
    else if(head[i]->next->key==-1) cout <<"leaf, ";
    else cout << "internal node, ";
    print_list(i);
  }

  
  return 0;
}