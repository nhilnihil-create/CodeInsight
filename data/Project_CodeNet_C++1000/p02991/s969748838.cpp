#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct Node{
    int id;
    int v;
    bool done = false;
    Node(int id, int v=1e9): id(id), v(v) {}
    Node(): id(0), v(1e9) {}
};

bool operator>(Node a, Node  b){
    return a.v > b.v;
}

struct Edge{
    int from, to, id;
    int cost;
    Edge(int from, int to, int cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

struct Graph{
    int N;
    vector<vector<Edge>> adj;
    vector<Node> node;

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, int cost=1, int id=-1){
        Edge e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge> get_adj(Node node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void reset(){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = 1e9;
        }
    }
};

int main(void){
    int N,M; cin >> N >> M;
    Graph G(3*N);
    REP(i,M){
        int u,v; cin >> u >> v; u--; v--;
        G.add_edge(3*u, 3*v+1);
        G.add_edge(3*u+1, 3*v+2);
        G.add_edge(3*u+2, 3*v);
    }
    int S,T; cin >> S >> T; S--; T--;
    queue<Node> q;
    q.push(Node(3*S,0));
    while(q.size()){
        Node n = q.front(); q.pop();
        if(G.node[n.id].done) continue;
        G.node[n.id].done = true;
        if(chmin(G.node[n.id].v, n.v)){
            for(Edge e : G.get_adj(n)) q.push(Node(e.to, n.v+1));
        }
    }
    int ans = G.node[3*T].v;
    cout << (ans<1e9 ? ans/3 : -1) << endl;
    return 0;
}