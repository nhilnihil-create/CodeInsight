#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main(){

    int V, E;
    cin >> V >> E;
    vector<vector<int>> edge(V);
    vector<int> count_in(V);
    for(int i = 0; i < V; i++){
        count_in[i] = 0;
    }

    int s, t;
    for(int i = 0; i < E; i++){
        cin >> s >> t;
        edge[s].emplace_back(t);
        count_in[t]++;
    }

    queue<int> q;
    for(int i = 0; i < V; i++){
        if(count_in[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        if(count_in[temp] == 0){
            ans.emplace_back(temp);
            for(int i = 0; i < (int)edge[temp].size(); i++){
                int to = edge[temp][i];
                count_in[to]--;
                if(count_in[to] == 0){
                    q.push(to);
                }
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
