#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> G[3 * N];
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u * 3].push_back(v * 3 + 1);
        G[u * 3 + 1].push_back(v * 3 + 2);
        G[u * 3 + 2].push_back(v * 3);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<int> d(3 * N);
    vector<int> used(3 * N, -1);
    queue<P> q;
    q.push(P(3 * s, 0));
    used[3 * s] = 1;
    while(!q.empty()){
        P v = q.front();
        q.pop();
        d[v.first] = v.second;
        for(int j: G[v.first]){
            if(used[j] == -1) {
                q.push(P(j, v.second + 1));
                used[j] = 1;
            }
        }
    }
    if(used[3 * t] == -1) cout << -1 << endl;
    else cout << d[3 * t] / 3 << endl;
}