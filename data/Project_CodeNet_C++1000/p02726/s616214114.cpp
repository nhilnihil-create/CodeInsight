#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X,Y; cin >> N >> X >> Y;X--,Y--;
    vector<vector<int>> dist(N,vector<int>(N,-1));
    for(int i = 0; i < N; i++){
        queue<int> que;
        que.push(i);
        dist[i][i] = 0;
       // cout << "b" << endl;
        
        while(!que.empty()){
            auto v = que.front();que.pop();
            vector<int> vec;
            if(v < N-1)vec.push_back(v+1);
            if(v > 0)vec.push_back(v-1);
            if(v == X) vec.push_back(Y);
            if(v == Y) vec.push_back(X);
            for(auto u:vec){
                if(dist[i][u]==-1){
                    dist[i][u] = dist[i][v] + 1;
                    que.push(u);
                }
            }
        }
    }
    //cout << "a" << endl;
    vector<int> ans(N,0);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            ans[dist[i][j]]++;
        }
    }
    for(int i = 1; i < N; i++) cout << ans[i] << endl;
    
}


