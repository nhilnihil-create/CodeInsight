#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
const int INF = 1000000000;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e[u].push_back(v);
    }

    int s,t;
    cin >> s >> t;
    s--,t--;

    vector<vector<int>> d(n,vector<int>(3,INF));

    d[s][0] = 0;
    queue<pair<int,int>> que;
    que.push(make_pair(s,0));

    while(que.size()){
        int v,mod;
        v = que.front().first;
        mod = que.front().second;
        que.pop();

        for(int next:e[v]){
            if(d[next][(mod+1)%3] > d[v][mod] + 1){
                d[next][(mod+1)%3] = d[v][mod] + 1;
                que.push(make_pair(next,(mod+1)%3));
            }
        }
    }

    cout << (d[t][0] == INF ? -1 : d[t][0] / 3) << endl;
}
