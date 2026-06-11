#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}

};

class Dijkstra{
	using Point = pair<ll,ll>;
	vector<ll> dist;
public:
	void CalcShortestPath(int start,ConnectNodeInfo& connect){
		dist.resize(connect.size(),1LL<<60);
		dist[start] = 0;

		priority_queue<Point,vector<Point>,greater<Point>> Q;
		Q.emplace(0,start);
		while(!Q.empty()){
			auto p = Q.top();
			Q.pop();
			int v = p.second;
			if(dist[v]<p.first){
				continue;
			}
			for(auto e:connect[v]){
				if(dist[e.first]>dist[v]+e.second){
					dist[e.first] = dist[v]+e.second;
					Q.emplace(dist[e.first],e.first);
				}
			}
		}
	}
	ll GetDistance(int i){
		return dist[i];
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),M=in();
	ConnectNodeInfo connect(3*N);
	REP(i,M){
		int u=in()-1,v=in()-1;
		connect.AddDirectionalConnection(3*u,3*v+1,1);
		connect.AddDirectionalConnection(3*u+1,3*v+2,1);
		connect.AddDirectionalConnection(3*u+2,3*v,1);
	}

	int s=in()-1,t=in()-1;
	ll minK = 1ll<<60;
	REP(i,3){
		Dijkstra Dij;
		Dij.CalcShortestPath(3*s+i,connect);
		REP(j,3){
			if(Dij.GetDistance(3*t+j)<1ll<<60 && !(Dij.GetDistance(3*t+j)%3ll)){
				chmin(minK,Dij.GetDistance(3*t+j)/3ll);
			}
		}
	}
	out(minK>=1ll<<60 ? -1 : minK);
	return 0;
}
