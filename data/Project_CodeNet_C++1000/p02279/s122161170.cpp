#include<bits/stdc++.h>
#define N 100005
using namespace std;
int in,id,k,a,rev[N];
/* struct declaration */

struct node {

  int key;

  struct node *next;

};

typedef struct node *NodePointer;

/* prototype declaration */

NodePointer insert(int,int);

NodePointer finditem(int,int);

void listprint(void);

NodePointer make_1node(int, NodePointer);


/* Global Variable head */

NodePointer head[N];

NodePointer insert(int keydata,int idx)//keydataがリストになかったらそれをリストに追加する
{
  NodePointer newnode;

  newnode = make_1node(keydata, head[idx]->next);
  head[idx]->next = newnode;
    
  return newnode;
}

NodePointer make_1node(int keydata, NodePointer p)//ノードを追加する
{
  NodePointer n;

  n = (NodePointer)malloc(sizeof(struct node));
  
  n->key = keydata;
  n->next = p;

  return n;
}

bool used[N];
int dep[N],par[N],z[N];

void dfs(int x,int d){
  dep[x]=d;
  int f=0;
  NodePointer n;
  for (n = head[x]->next; n != NULL; n = n->next) dfs(n->key,d+1),f=1;
  if(!f&&z[x]!=3)z[x]=1;
  else if(z[x]!=3)z[x]=2;
}

int main(){
  cin>>in;
  for(int i=0;i<in;i++)head[i]=make_1node(-1,head[i]);
  for(int i=0;i<in;i++){
    cin>>id>>k;
    for(int j=0;j<k;j++){
      cin>>a;
      insert(a,id);
      used[a]=true;
      par[a]=id;
    }
  }
  for(int i=0;i<in;i++)
    if(!used[i])z[i]=3,dfs(i,0),par[i]=-1;
  for(int i=0;i<in;i++){
    cout<<"node "<<i<<": parent = "<<par[i]<<", depth = "<<dep[i]<<", ";
    if(z[i]==2)cout<<"internal node, [";
    if(z[i]==1)cout<<"leaf, [";
    if(z[i]==3)cout<<"root, [";
    int y=0;
    NodePointer n;
    for (n = head[i]->next; n != NULL; n = n->next)rev[y++]=n->key;
    for(int j=y-1;j>=0;j--){
      if(j!=y-1)cout<<", ";
      cout<<rev[j];
    }
    cout<<"]"<<endl;
  }
  return 0;
}