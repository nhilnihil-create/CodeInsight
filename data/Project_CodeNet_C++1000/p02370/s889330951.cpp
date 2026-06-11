#include<bits/stdc++.h>

const static int WHITE = 0;
const static int GRAY = 1;

std::vector<int> color, indeg, ans;
std::vector<std::vector<int>> earray;
int v;
std::queue<int> q;

void bfs(int u){
    q.push(u);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i < earray[node].size(); i++){
            indeg[ earray[node][i] ]--;
            if(indeg[ earray[node][i] ] == 0 && color[ earray[node][i] ] == WHITE){
                color[ earray[node][i] ] = GRAY;
                q.push(earray[node][i]);
            }
        }
    }
}

void topologicalSort(){
    for(int i = 0; i < v; i++){
        if(indeg[i] == 0 && color[i] == WHITE){
            bfs(i);
        }
    }
}

int main(void){
    
    int e, s, t;
    
    std::cin >> v >> e;
    color.resize(v);
    indeg.resize(v);
    earray.resize(v);

    for(int i = 0; i < v; i++){
        indeg[i] = 0;
    }

    for(int i = 0; i < e; i++){
        std::cin >> s >> t;
        earray[s].push_back(t);       
    }

    for(int i = 0; i < v; i++){
        for(int j = 0; j < earray[i].size(); j++){
            indeg[ earray[i][j] ]++;
        }
    }

    topologicalSort();

    for(int i = 0; i < v; i++){
        std::cout << ans[i] << std::endl;
    }

    return 0;

}
