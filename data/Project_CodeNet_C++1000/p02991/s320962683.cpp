#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,S,T;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<long long int> len(3*N,-1);

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
    }

    cin >> S >> T;

    S--;
    T--;

    queue<int> Q;
    Q.push(3*S);
    len[3*S] = 0;

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(int i=0;i<graph[now/3].size();i++){
            if(len[3*graph[now/3][i] + (now%3+1)%3]==-1){
                len[3*graph[now/3][i]+(now%3+1)%3] = len[now] + 1;
                Q.push(3*graph[now/3][i]+(now%3+1)%3);
            }
        }
    }

    if(len[3*T]==-1){
        cout << -1 << endl;
    }else{
        cout << len[3*T]/3 << endl;
    }
}