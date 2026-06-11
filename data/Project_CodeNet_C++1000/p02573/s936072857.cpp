#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int N,M;
    cin >> N >> M;


    vector<vector<int>> G(N);
    vector<pair<int,int>> p(M);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        p[i].first = min(a,b)-1;
        p[i].second = max(a,b)-1;
    }
    sort(p.begin(),p.end());

    int preva = 0, prevb = 0;
    for(int i=0;i<M;i++){
        if(preva == p[i].first && prevb == p[i].second) continue;

        preva = p[i].first; prevb = p[i].second;
        G[preva].push_back(prevb);
        G[prevb].push_back(preva);
    }

    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) if(rel[i][j]) cout << 'o'; else cout << 'x';
        cout << "\n";
    }
    return 0;
    */

    vector<int> dist(N,-1);
    queue<int> q;
    int ans = 0;

    for(int v=0;v<N;v++){
        if(dist[v]!=-1) continue;

        int tmp = 0;
        dist[v] = 0;
        q.push(v);

        while(!q.empty()){
            int v = q.front();
            q.pop();
            tmp++;

            for(int nv:G[v]){
                if(dist[nv]!=-1) continue;
                dist[nv] = dist[v]+1;
                q.push(nv);
            }
        }
        ans = max(ans,tmp);
    }

    cout << ans << endl;
    return 0;

}