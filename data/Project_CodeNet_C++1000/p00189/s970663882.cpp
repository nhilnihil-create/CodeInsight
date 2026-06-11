#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <utility>

#define dprintf(s,...) printf("%s:%d" s,__func__,__LINE__,__VA_ARGS__)
using namespace std;

typedef pair<int,int> P;
typedef long long int ll;

class Edge{
public:
  int to,cost;
  Edge(int t,int c){
    to = t;
    cost = c;
  }
};

int n,k;
int d[10][10];
vector<Edge> G[10];

void dijekstra(int s){

  priority_queue<P, vector<P>, greater<P> > qu;

  qu.push(P(0,s));
  d[s][s]=0;
  
  while(!qu.empty()){

    P p = qu.top();
    int v = p.second; 
    qu.pop();

    if(d[s][v] < p.first) continue;

    for(int i=0; i<G[v].size(); i++){
      Edge e = G[v][i];
      
      if(d[s][v]+e.cost < d[s][e.to]){
	d[s][e.to] = d[s][v]+e.cost;
	qu.push(P(d[s][e.to], e.to));
      }
    }
    
  }

}

void solve(){

  for(int i=0;i<k;i++)
    for(int j=0;j<k;j++){
      d[i][j]=INT_MAX/3;
    }

  for(int i=0;i<k;i++){
    dijekstra(i);
  }
}


int main(){

  ios_base::sync_with_stdio(false);
  
  while(1){

    k=0;
    
    cin>>n;
    if(n==0) break;
    
    
    for(int i=0;i<n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      Edge e1(a,c),e2(b,c);
      G[a].push_back(e2);
      G[b].push_back(e1);
      k = max(k,max(a,b));
    }
    k++;
    //cout<<"k="<<k<<endl;
    solve();
    
    int sum[10];
    int ans, min_cost=INT_MAX/3;
    fill(sum,sum+10,0);

    for(int i=k-1;i>=0;i--){
      //cout<<i<<":";
      for(int j=0; j<k; j++){
	//cout<<d[i][j]<<" ";
	sum[i] += d[i][j];
      }
      //cout<<endl;
      if(sum[i] <= min_cost){
	ans = i;
	min_cost = sum[i];
      }
    }
    cout<<ans<<" "<<min_cost<<endl;
    for(int i=0;i<10;i++){
      G[i].erase(G[i].begin(), G[i].end());
    }    
  }


  
  
  return 0;
}