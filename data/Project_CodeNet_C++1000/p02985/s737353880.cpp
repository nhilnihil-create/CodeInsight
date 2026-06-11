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

template<typename T>
struct Node{
    int id;
    T v;
    bool done = false;
    Node(int id, T v=1e9): id(id), v(v) {}
    Node(): id(0), v(1e9) {}
};

template<typename T>
bool operator>(Node<T> a, Node<T>  b){
    return a.v > b.v;
}

template<typename T>
struct Edge{
    int from, to, id;
    T cost;
    Edge(int from, int to, T cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

template<typename T>
struct Graph{
    int N;
    vector<vector<Edge<T>>> adj;
    vector<Node<T>> node;

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, T cost=1, int id=-1){
        Edge<T> e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge<T>> get_adj(Node<T> node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void reset(){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = 1e9;
        }
    }
};

int N,K;
Graph<int> G;
VI fin;

void dfs(int to, int from){
    if(from >= 0) G.node[to].v = K-fin[from];
    else G.node[to].v = K;
    
    fin[to] = 1;
    for(Edge<int> e : G.adj[to]){
        if(G.node[e.to].done) fin[to]++;
    }

    G.node[to].done = true;
    for(Edge<int> e : G.adj[to]){
        if(G.node[e.to].done) continue;
        dfs(e.to, e.from);
        fin[to]++;
    }
    return;
}

int main(void){
    cin >> N >> K;
    G.assign(N); fin.assign(N,0);
    REP(i,N-1){
        int a,b; cin >> a >> b; a--; b--;
        G.add_edge(a,b);
        G.add_edge(b,a);
    }
    dfs(0,-1);
    ll ans = 1;
    REP(i,N){
        ans *= G.node[i].v;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}