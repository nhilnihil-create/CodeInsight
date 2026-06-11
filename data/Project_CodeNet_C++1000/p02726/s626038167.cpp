#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printq(queue<int> que){
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}

int main(void){
    int n, x, y;
    cin >> n >> x >> y;
    queue<int> que;
    vector<vector<int>> g(n+1);
    g[x].push_back(y); g[y].push_back(x);
    g[1].push_back(2); g[n].push_back(n-1);
    for(int i = 2; i <= n-1; i++){
        g[i].push_back(i-1);
        g[i].push_back(i+1);
    }
    vector<int> ans(n, 0);
    for(int i = 1; i <= n; i++){
        vector<bool> visit(n+1, false);
        visit[i] = true;
        que.push(i);
        vector<int> dist(n+1, 0);
        int count = 1;
        while(count < n){
            //printq(que);
            int v = que.front();
            //printf("v %d\n", v);
            que.pop();
            for(int j : g[v]){
                if((v == j+1 || v == j-1 || (v == x && j == y) || (v == y && j == x)) && !visit[j]){
                    //printf("visit %d from %d\n", j, v);
                    que.push(j);
                    visit[j] = true; count++;
                    dist[j] = dist[v] + 1;
                }
            }
        }
        while(!que.empty()) que.pop();
        for(int j = i+1; j <= n; j++){
            ans[dist[j]]++;
            //printf("%d -> %d : %d\n", i, j, dist[j]);
        }
    }
    for(int i = 1; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
