#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct node{int p,l,r;};

node t[MAX];
int n,D[MAX];

void print(int u){
  int i,c;
  cout << "node "<< u << ": ";
  cout << "parent = "<<t[u].p<<", ";
  cout << "depth = "<<D[u]<<", ";

  if(t[u].p==NIL) cout<<"root, ";
  else if(t[u].l==NIL) cout<<"leaf, ";
  else cout<<"internal node, ";
  cout<<"[";

  for(i=0,c=t[u].l;c!=NIL;i++,c=t[c].r){
    if(i) cout<<", ";
    cout<<c;
  }
  cout<<"]"<<endl;
}

int rec(int u,int p)
{
  D[u]=p;
  if(t[u].r!=NIL) rec(t[u].r,p);
  if(t[u].l!=NIL) rec(t[u].l,p+1);
}

int main(){
  int i,j,d,v,c,l,r;
  cin>>n;
  for(i=0;i<n;i++) t[i].p=t[i].l=t[i].r=NIL;

  for(i=0;i<n;i++){
    cin >> v >>d;
    for(j=0;j<d;j++){
	cin>>c;
	if(j==0) t[v].l=c;
	else t[l].r=c;
	l=c;
	t[c].p=v;
      }
  }
  for(i=0;i<n;i++){
    if(t[i].p==NIL) r=i;
  }

  rec(r,0);
  for(i=0;i<n;i++) print(i);

  return 0;
}

