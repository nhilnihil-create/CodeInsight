#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,K,ans;
    cin >> N >> K;

    ans = K;

    vector<vector<int>> graph(N);
    vector<int> color(N,-1);

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> Q;
    Q.push(0);
    ans = K;
    color[0] = 0;

    while(!Q.empty()){
        int now = Q.front(),sub;
        Q.pop();

        if(now==0){
            sub = 1;
        }else{
            sub = 2;
        }

        for(int i=0;i<graph[now].size();i++){
            if(color[graph[now][i]]==-1){
                color[graph[now][i]] = 0;
                Q.push(graph[now][i]);
                ans *= (K-sub);
                ans %= 1000000007;
                sub++;
            }
        }
    }
    cout << ans << endl;
}