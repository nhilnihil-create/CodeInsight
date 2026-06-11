#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


class Solution{

public:
    int minRoads(const vector<vector<int>>& g){

        vector<bool> visited(g.size(), false);
        int res = 0;
        for(int i = 0; i < g.size(); i ++)
            if(!visited[i]){
                dfs(g, i, visited);
                res ++;
            }
        return res - 1;
    }

private:
    void dfs(const vector<vector<int>>& g, int v, vector<bool>& visited){

        visited[v] = true;
        for(int w: g[v])
            if(!visited[w]) dfs(g, w, visited);
    }
};

int main() {

    int N, M; scanf("%d%d", &N, &M);
    vector<vector<int>> g(N);

    int a, b;
    while(M --){
        scanf("%d%d", &a, &b);
        a --, b --;
        g[a].push_back(b), g[b].push_back(a);
    }
    printf("%d\n", Solution().minRoads(g));
    
    return 0;
}
