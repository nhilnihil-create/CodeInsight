#include <bits/stdc++.h>
#define REP(i,n) for (long i=0;i<(n);i++)
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define RREP(i,n) for(long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl;
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl;
#define dump(x)  cerr << #x << " => " << (x) << endl;
#define CLR(vec) { REP(i,vec.size()) vec[i] = 0; } 
#define llINF (long long) 9223372036854775807
#define loINF (long) 2147483647
#define shINF (short) 32767
#define SORT(c) sort((c).begin(),(c).end())

using namespace std;
typedef vector<long> VI;
typedef vector<VI> VVI;
typedef pair<long,long> pr;
struct Order {
	bool operator() (pr const& a,pr const& b) const {
		return a.first > b.first || ((a.first == b.first) && (a.second > b.second));
	}
};
typedef priority_queue<pr,vector<pr>,Order> pq;

class Prim {
private:
	vector<vector<pr>> E; //隣接行列
	pq mincost;
	vector<bool> used;
	size_t V;
public:
	Prim() : V(0) {}

	Prim(size_t v) : 
		V(v),E(v,vector<pr>(0)),used(v,false){}
		
	size_t size() {return V;}

	void add_edge_directed(long start,long goal,long weight){
		E[start].push_back(pr(goal,weight));
	}

	void add_edge_undirected(long start,long goal,long weight){
		E[start].push_back(pr(goal,weight));
		E[goal].push_back(pr(start,weight));
	}

	long min_spanning_tree(void){
		long minval = 0;
		mincost.push(pr(0,0));
		while(1) {
			if (mincost.empty()) break;
			pr node = mincost.top();
			mincost.pop();
			if (used[node.second]) continue;
			minval += node.first;
			used[node.second] = true;

			REP(i,E[node.second].size()){
				if (!used[E[node.second][i].first])
					mincost.push(pr(E[node.second][i].second,E[node.second][i].first));
			}
					
		}

		return minval;
	}

};


int main(void){
	long V,E;
	long u,v,w;
	cin >> V >> E;
	Prim prim(V);

	REP(i,E){
		cin >> u >> v >> w;
		prim.add_edge_undirected(u,v,w);
	}

	cout << prim.min_spanning_tree() << endl;

	return 0;
}
