#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> G[N];
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    queue<P> q, temp;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    q.push(P(s, 0));
    vector<vector<int>> d(3, vector<int>(N, -1));
    d[0][s] = 0;
    while(!q.empty()){
        P v = q.front();
        q.pop();
        temp.push(v);
        while(!temp.empty()){
            P u = temp.front();
            temp.pop();
            for(int j: G[u.first]){
                int te = u.second + 1 - v.second;
                if(te < 3 && d[te][j] == -1){
                    temp.push(P(j, u.second + 1));
                    d[te][j] = u.second + 1;
                }
                else if(te == 3 && d[0][j] == -1){
                    q.push(P(j, u.second + 1));
                    d[0][j] = u.second + 1; 
                }
            }
        }
    }
    if(d[0][t] == -1) cout << -1 << endl;
    else cout << d[0][t] / 3 << endl;
}
