#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000
class WarshallFloyed{
public:
	int V; //????????°
	ll D[256][256]; //i??????j???????????????D[i][j]
	WarshallFloyed(){}
	WarshallFloyed(int _V){
		V = _V;
	}
	void init(){
		for(int i = 0; i < V; ++i){
			for(int j = 0; j < V; ++j){
				if(i == j){
					D[i][j] = 0;
				}
				else{
					D[i][j] = INF;
				}
			}
		}
	}
	bool addEdge(int from,int to,ll cost){
		if(D[from][to] != INF)return false;
		D[from][to] = cost;
		return true;
	}
	bool getShortestPath(){
		for(int k = 0; k < V; ++k){
			for(int i = 0; i < V; ++i){
				for(int j = 0; j < V; ++j){
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
		return true;
	}
	bool isNegativeCycle(){
		for(int i = 0; i < V; ++i){
			if(D[i][i] < 0){
				return true;
			}
		}
		return false;
	}

	void print(){
		for(int i = 0; i < V; ++i){
			for(int j = 0; j < V; ++j){
				if(D[i][j] >= 1e9*2) printf("INF%c",j==V-1?'\n':' ');
				else printf("%lld%c",D[i][j],j==V-1?'\n':' ');
			}
		}
	}
};

class Belman{
public:
	struct edge{
		ll from,to,cost;
		edge(){}
		edge(ll _from, ll _to, ll _cost){
			from = _from;
			to = _to;
			cost = _cost;
		}
	};
	long long d[10001];
	edge graph[10001];
	int V,E;
	int idx;
	Belman(){}
	Belman(int _V,int _E){
		V = _V;
		E = _E;
		idx = 0;
	}
	bool init(){
		for(int i = 0; i < 10001; ++i){
			d[i] = INF;
			graph[i] = edge(0,0,0);
		}
	}
	bool addEdge(ll from, ll to, ll cost){
		graph[idx] = edge(from,to,cost);
		idx++;
		return true;
	}
	int getShortestPath(ll start){
		d[start] = 0;
		int cnt = 0;
		while(true){
			bool update = false;
			for(int i = 0; i < E; ++i){
				edge e = graph[i];
				if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					update = true;
				}
			}
			if(!update)break;
			if(cnt == V-1)return -1;
			cnt++;
		}
		return 0;
	}
	void print(){
		for(int i = 0; i < V; ++i){
			printf("%lld%c",d[i],i == V-1?'\n':' ');
		}
	}
};

struct UnionFind{
    int N,par[1000],sz[1000];
    UnionFind(){
        N=1000;
        for(int i = 0; i < N; ++i){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(sz[x] < sz[y]) swap(x,y);
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
    }
    int getSize(int x){
        return sz[find(x)];
    }
};

int main(){
	ll v,e;
	cin >> v >> e;
	ll r;
	cin >> r;
	Belman B = Belman(v,e);
	B.init();
	for(int i = 0; i < e; ++i){
		ll a,b,c;
		cin >> a >> b >> c;
		B.addEdge(a,b,c);
	}
	if(B.getShortestPath(r) == -1){
		puts("NEGATIVE CYCLE");
	}
	else{
		for(int i = 0; i < v; ++i){
			if(B.d[i] != INF)printf("%d\n",B.d[i]);
			else puts("INF");
		}
	}
	return 0;
}