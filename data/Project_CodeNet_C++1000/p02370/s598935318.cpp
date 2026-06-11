#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

struct topological_sort{
    vector<vector<int>> graph;
    vector<bool> done,open;
    vector<int> res;
    bool success;
    topological_sort(vector<vector<int>> &graph):graph(graph),done(graph.size()),open(graph.size()){
        success=true;
        rep(i,0,graph.size()){
            if(!dfs(i)){
                success=false;
                break;
            }
        }
        reverse(res.begin(),res.end());
    }
    bool dfs(int v){
        if(open[v]) return false;
        if(done[v]) return true;
        open[v]=true;
        done[v]=true;
        for(auto &u:graph[v]) if(!dfs(u)) return false;
        open[v]=false;
        res.push_back(v);
        return true;
    }
};

void solve(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    rep(i,0,e){
        int s,t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    topological_sort ts(graph);
    rep(i,0,v) cout << ts.res[i] << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}