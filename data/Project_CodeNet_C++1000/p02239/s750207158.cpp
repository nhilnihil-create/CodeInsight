#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int n;
vector <int> G[101];
queue <int> Q;
int  d[100];
int  dis[101];


int visit(int x){
  int t,i;
  
  Q.push(x);
  dis[x] = 0;
  d[x] = 1;

  while(Q.empty() == false) {
    
    // cout << "start Q" <<endl;

    t = Q.front();
    Q.pop();

    for(i=0; i<G[t].size();i++) {
      if(d[G[t][i]] == 0 ) {
	d[G[t][i]] = 1;
	dis[G[t][i]] = dis[t] + 1;

	Q.push(G[t][i]);
      }

    }
  }
}
    
int main() {
  
  int i,j,k,l,u,a,t;
  
  
  scanf("%d",&n);

  
  
  for(i=0;i<n;i++){
    d[i] = 0;
    dis[i] = -1;
    scanf("%d %d ",&k,&u);
    
    for(j=0;j<u;j++) {
      scanf("%d",&a);
      G[k-1].push_back(a-1);
      // printf("G[%d][%d] = 1\n",i,k-1);
    }
  }
  
  
  visit(0);

  

  for(i=0;i<n;i++) cout << i+1<<" " << dis[i] <<endl;



  return 0;

    
    
}