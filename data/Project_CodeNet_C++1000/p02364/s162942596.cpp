#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 2147483647;
int prime = 10e9+7;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> siz;

    UnionFind(int N) : par(N), siz(N, 1LL) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

struct Edge{
    int from,to,cost;
    bool operator<(const Edge& another) const{
        return cost < another.cost;
    }
    bool operator>(const Edge& another) const{
        return cost > another.cost;
    }
};

class uGrapf{
    vector<vector<P>> grapf;
    vector<int> d;
    bool loop = false;
    public:
    uGrapf(int n){
        this->grapf.resize(n);
        this->d.resize(grapf.size(),max_int);
    }
    uGrapf(){
        this->grapf.resize(10e6);
        this->d.resize(grapf.size(),max_int);
    }
    /* 辺の二つ、コストの順
     */
    void edge(int edge1,int edge2,int weight=1){
        P p = P(edge2,weight);
        grapf[edge1].push_back(p);
        p = P(edge1,weight);
        grapf[edge2].push_back(p);
    }
    void dijkstra(int n){
        d[n] = 0;
        PQ(que);
        que.emplace(0,n);
        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(P e: grapf[v]){
                if(d[e.first] > d[v]+e.second){
                    d[e.first] = d[v]+e.second;
                    que.emplace(d[e.first],e.first);
                }
            }
        }
    }
    void bellmanford(int n){
        fill(d.begin(), d.end(), max_int);
        d[n] = 0;
        bool update = true;
        int cnt = 0;
        while(update){
            update = false;
            REP(i,grapf.size()){
                REP(j,grapf[i].size()){
                    if(d[i] != max_int && d[grapf[i][j].first] > d[i] + grapf[i][j].second){
                        d[grapf[i][j].first] = d[i] + grapf[i][j].second;
                        update = true;
                    }
                }
            }
            cnt++;
            if(cnt > grapf.size()){
                loop = true;
                return;
            }
        }
    }
    
    int prim(int n){
        UnionFind uf(grapf.size());
        priority_queue<Edge,vector<Edge>,greater<Edge>> que;
        Edge e;
        REP(i,grapf[n].size()){
            e.from = n;e.to = grapf[n][i].first;e.cost = grapf[n][i].second;
            que.push(e);
        }
        int cnt = 0;
        while(!que.empty()){
            e = que.top();
            que.pop();
            if(!uf.same(e.from,e.to)){
                uf.unite(e.from,e.to);
                cnt += e.cost;
                REP(i,grapf[e.to].size()){
                    if(!uf.same(e.to,grapf[e.to][i].first)){
                        Edge tmp;
                        tmp.from = e.to;tmp.to = grapf[e.to][i].first;tmp.cost = grapf[e.to][i].second;
                        que.push(tmp);
                    }
                }
            }
        }
        return cnt;
    }
    
    void print_AOJ(){
        if(loop){
            print("NEGATIVE CYCLE");
            return;
        }
        REP(i,d.size()){
            if(d[i] == max_int){
                print("INF");
            }
            else{
                print(d[i]);
            }
        }
    }
    void De(){
        REP(i,grapf.size()){
            cout << "{";
            for(P p:grapf[i]){
                cout << "{" << p.first << "," << p.second << "}";
            }
            cout << "}\n";
        }
        Debug(d);
    }
};


signed main(){
    int v,e,r=0;
    cin >> v >> e;
    uGrapf g(v);
    REP(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        g.edge(s,t,d);
    }
    print(g.prim(r));

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}

//key以上の初めてのitr
int nibul(auto a,auto b){return lower_bound(All(a),b) - a.begin();}
//key以下の最後のitr
int nibuu(auto a,auto b){return upper_bound(All(a),b) - a.begin()-1;}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

