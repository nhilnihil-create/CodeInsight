#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

Graph g;
ll n;
vector<ll>dist;

/*トポロジカルソートを行う
DAGでない場合にはsize０のvectorを返す*/

struct TopologicalSort{
    int v;
    vector<vector<int> >g,g_len;
    vector<int>deg,res;//degは頂点に入ってくる辺の数
    TopologicalSort(int n) : v(n),g(v),deg(v,0),g_len(v){}
    void add_edge(int from,int to){
        g[from].push_back(to);
        g_len[to].push_back(from);
        deg[to]++;
    }
    vector<int> solve(){
        queue<int>que;
        rep(i,v){
            if(deg[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int p = que.front();
            que.pop();
            res.push_back(p);
            for(int v:g[p]){
                if(--deg[v]==0){
                    que.push(v);
                }
            }
        }
        if(*max_element(deg.begin(),deg.end())==0){
            return res;
        }
        else{
            return vector<int>();
        }
    }
    bool unique(){//解の一意性を判定する
        for(int i=0;i<v-1;i++){
            int from = res[i];
            int to = res[i+1];
            bool flg = false;
            for(int x:g[from]){
                if(x==to)flg=true;
            }
            if(!flg){
                return false;
            }
        }
        return true;
    }
    int longest_len(){
        vector<int>dist(v,0);
        for(int i=0;i<v;i++){
            for(int x:g_len[res[i]]){
                dist[res[i]]=max(dist[res[i]],dist[x]+1);
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};

int main(){
    cin >> n;
    TopologicalSort tps(n*n);
    rep(i,n){
        int past = 0;
        rep(j,n-1){
            int a;
            cin >> a;
            a--;
            int l = min(i,a);
            int r = max(i,a);
            int nx = l*n+r;
            tps.add_edge(past,nx);
            past = nx;
        }
    }
    //DAGの判定
    auto vec = tps.solve();
    if(vec.size()==0){
        cout << -1 << endl;
        return 0;
    }
    cout << tps.longest_len() << endl;
    return 0;
}
