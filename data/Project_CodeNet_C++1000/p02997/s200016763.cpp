#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, K; cin >> N >> K;
    if((N*(N-1)/2) - (N-1) < K){
        cout << -1 << endl;
        return 0;
    }
    int M = N*(N-1)/2 - K;
    vector<P> edge;
    // とりあえず連結グラフにするのに必要な辺を追加する
    rep(i, N-1){
        edge.push_back({1, i+2});
    }
    int cnt = N-1;
    for(int i = 2;i <= N; i++){
        for(int j = i+1;j <= N; j++){
            if(cnt >= M) break;
            edge.push_back({i, j});
            cnt++;
        }
        if(cnt >= M) break;
    }
    cout << M << endl;
    rep(i, M){
        cout << edge[i].first << " " << edge[i].second << endl;
    }
    return 0;
}
