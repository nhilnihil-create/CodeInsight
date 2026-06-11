#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
struct UndirectedGraph
{
    using Pint = pair<int, int>;
    using Plint = pair<ll, int>;
    int V;
    int E;
    int dDefault;
    vector<ll> weights;
    vector<vector<Pint>> to;
    vector<Pint> edges;
 
    UndirectedGraph(int V, ll dDefault=-1) : V(V), E(0), dDefault(dDefault),
                             to(vector<vector<Pint>>(V)) {}
 
    void add_edge(int v1, int v2, ll w)
    {
        to[v1].push_back(Pint(v2, E));
        // to[v2].push_back(Pint(v1, E));
        edges.push_back(Pint(v1, v2));
        weights.push_back(w);
        E++;
    }
 
    vector<ll> dist;
    void dijkstra(int start)
    {
        dist = vector<ll>(V, dDefault);
        priority_queue<Plint, vector<Plint>, greater<Plint>> pq;
        pq.push(Plint(0, start));
 
        while (!pq.empty()) {
            Plint p = pq.top(); pq.pop();
            int v = p.second;
            if (dist[v] >= 0 && dist[v] <= p.first) continue;
            dist[v] = p.first;
            // cout << "dist[" << v << "] = " << p.first << endl;
            for (auto vnxt : to[v]) {
                ll dnxt = dist[v] + weights[vnxt.second];
                if (dnxt < dist[vnxt.first] || dist[vnxt.first] < 0) {
                    pq.push(Plint(dnxt, vnxt.first));
                }
            }
        }
    }
};

int main(){
    ll N;
    cin>>N;
    ll M;
    cin>>M;
    vl u(M);
    vl v(M);
    F0R(i,M){
        cin>>u[i]>>v[i];
    }
    ll s;
    cin>>s;
    ll t;
    cin>>t;
    UndirectedGraph graph(N*3+10);
    F0R(i,M){
        graph.add_edge(u[i]*3,v[i]*3+1,1);
        graph.add_edge(u[i]*3+1,v[i]*3+2,1);
        graph.add_edge(u[i]*3+2,v[i]*3,1);
    }
    graph.dijkstra(s*3);
    int ret=graph.dist[t*3];
    cout<<(ret>0?ret/3:-1)<<endl;
    return 0;
}
