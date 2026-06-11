#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;
  vector<ll> next;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
	next.resize(V);
    for(int i=0;i<V;i++){
      d[i] = 1000000;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    for(int i=0;i<V;i++){
      d[i] = 1000000;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
		  next[e.to]=v;
        }
      }
    }
  }
};


main(){
	int n,m;
	cin >> n >> m;
	graph g(n);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		g.add_edge(a-1,b-1,1);
		g.add_edge(b-1,a-1,1);
	}

	g.dijkstra(0);
	for(int i=1;i<n;i++){
		if(g.d[i]==1000000){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	for(int i=1;i<n;i++){
		cout << g.next[i]+1 << endl;
	}

	
	return 0;
}
