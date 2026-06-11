#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl


#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRINT(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr int dx[4] = {0,1,0,-1};
constexpr int dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;


void dijekstra(int start,vector<int> &D,vector<vector<pair<int,long>>> &E){
	priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> que;
	vector<int> trace(E.size());
	D[start] = 0;
	trace[start] = start;
	que.push(make_pair(0,start));
	long d;int v;
	while(!que.empty()){
		pair<long,int> cur = que.top();que.pop();
		d = cur.first;v = cur.second;
		if (D[v] < d) continue; //既により最適が見つかっている
		for(int i = 0;i < E[v].size();i++){
			int next = E[v][i].first;
			long newCost = d + E[v][i].second;
			if (D[next] > newCost) {
				D[next] = newCost;
				trace[next] = v;
				que.push(make_pair(newCost,next));
			}
			else if (D[next] == newCost) {
				trace[next] = min(trace[next],v);
			}
		}
	}
}

int main(void){
	long V,E,R;
	long s,t,d;
	cin >> V >> E >> R;
	vector<vector<pair<int,long>>> e(V);
	vector<int> dist(V,loINF);
	REP(i,E){
		cin >> s >> t >> d;
		e[s].push_back(make_pair(t,d));
	}
	dijekstra(R,dist,e);
	REP(i,V) {
		if (dist[i] == loINF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
		
	return 0;
}
