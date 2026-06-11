#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define MAX_V 10000

vector<int> G[MAX_V];
list<int> out;
bool V[MAX_V];
int N;//頂点数
int indeg[MAX_V];

void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        out.push_back(u);
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            indeg[v]--;
            if(indeg[v] == 0 && !V[v]){
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort(){
    for(int i = 0; i < N; i++){
        indeg[i] = 0;
    }

    for(int u = 0; u < N; u++){
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            indeg[v]++;
        }
    }
    
    for(int u = 0; u < N; u++){
        if(indeg[u] == 0 && !V[u]) bfs(u);
    }

}

signed main(){
    int M;
    cin >> N >> M;
    int s,t;
    REP(i,M){
        cin >> s >> t;
        G[s].push_back(t);
    }
    tsort();
    for(list<int>::iterator it = out.begin(); it != out.end(); it++){
        cout << *it << endl;
    }
}
