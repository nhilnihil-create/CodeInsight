#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

static const int MAX = 100000;

vector<int>G[MAX];
list<int>Out;
bool V[MAX] = {false};
int N;
int indeg[MAX] = {0};

void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        Out.push_back(u);
        
        for(int i = 0;i < G[u].size();++i){
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
    for(int u = 0;u < N;++u){
        for(int i = 0;i < G[u].size();++i){
            int v = G[u][i];
            indeg[v]++;
        }
    }
    
    for(int u = 0;u < N;++u){
        if(indeg[u] == 0 && !V[u]){
            bfs(u);
        }
    }
    
    for(list<int>::iterator it = Out.begin();it != Out.end();++it){
        cout << *it << endl;
    }
}

int main(){
    int s,t,m;
    cin >> N >> m;
    
    for(int i = 0;i < m;++i){
        cin >> s >> t;
        G[s].push_back(t);
    }
    tsort();
}

