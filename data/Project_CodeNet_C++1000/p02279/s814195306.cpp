#include<bits/stdc++.h>
using namespace std;

struct tree{
  int p;
  int l;
  int r;
  int d;
};

tree t[100000];

void dfs(int n,int d){
  if(n==-1)return;
  t[n].d=d;
  dfs(t[n].r,d),dfs(t[n].l,d+1);
}

int main(){
  int n,a,b,c,tmp;
  cin>>n;
  for(int i=0;i<n;i++)t[i].l=-1,t[i].p=-1,t[i].r=-1,t[i].d=0;
  for(int i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    for(int j=0;j<b;j++){
      scanf("%d",&c);
      t[c].p=a;
      if(j)t[tmp].r=c;
      tmp=c;
      if(j==0)t[a].l=c;
    }
  }
  for(int i=0;i<n;i++)if(t[i].p==-1)dfs(i,0);
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,t[i].p,t[i].d);
    if(t[i].l==-1){
      if(t[i].p==-1)printf("root, []\n");
      else printf("leaf, []\n");
    }
    else{
      if(t[i].p==-1)printf("root, [");
      else printf("internal node, [");
      tmp=t[i].l;
      while(1){
	if(t[tmp].r==-1){
	  printf("%d]\n",tmp);
	  break;
	}
	printf("%d, ",tmp);
	tmp=t[tmp].r;
      }
    }
  }
  return 0;
}