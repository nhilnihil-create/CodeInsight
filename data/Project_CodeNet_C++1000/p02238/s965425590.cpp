#include <iostream>
using namespace std;

typedef pair<int, int> edge;

int vernum[101];
edge path[101][101];
int n;

edge found[101];

int t=0;
void dfs(int v){
    t++;
    found[v].first = t;
    int i=0;
    while(1){
        if(!path[v][i].first)
            break;
        if(!found[path[v][i].second].first){
            dfs(path[v][i].second);
        }
        i++;
    }
    t++;
    found[v].second = t;
}

int main() {
    int i, j;
    ios_base::sync_with_stdio(0);
    
    int e, v;
    cin >> n;
    
    for(i=1; i<=n; i++){
        cin >> vernum[i];
        cin >> e;
        for(j=0; j<e; j++){
            cin >> v;
            path[i][j] = make_pair(i, v);
        }
    }
    
    for(i=1; i<=n; i++){
        if(!found[i].first)
            dfs(i);
    }
    
    for(i=1; i<=n; i++){
        cout << vernum[i] << " " << found[i].first << " " << found[i].second << endl;
    }
    
    
    return 0;
}