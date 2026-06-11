#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define var auto
#define mod 1000000007
#define inf 2147483647
#define nil -1
#define mp make_pair
typedef long long ll;
using namespace std;

template <typename T>
inline void output(T a, int p) {
    if(p){
        cout << fixed << setprecision(p)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}
// end of template

class topological_sort{
public:
    int V;
    vector<int> vis, indeg, sorted;
    vector<vector<int>> edge;
    topological_sort(int v){
        V = v;
        vis.resize(v, 0);
        indeg.resize(v, 0);
        edge.resize(v);
    }
    
    void add(int from, int to){
        edge[from].push_back(to);
        indeg[to]++;
    }
    
    void bfs(int s){
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            sorted.push_back(f);
            rep(i, edge[f].size()){
                int e = edge[f][i];
                indeg[e]--;
                if (indeg[e] == 0 && !vis[e]) {
                    vis[e] = 1;
                    q.push(e);
                }
            }
        }
    }
    
    void sort(){
        rep(i, V){
            if (indeg[i] == 0 && !vis[i]) {
                bfs(i);
            }
        }
    }
    
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int V, E;
    cin >> V >> E;
    topological_sort ts(V);
    rep(i, E){
        int s, t;
        cin >> s >> t;
        ts.add(s, t);
    }
    ts.sort();
    
    rep(i, ts.sorted.size()){
        cout << ts.sorted[i] << endl;
    }
    
    return 0;
}