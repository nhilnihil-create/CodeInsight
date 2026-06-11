#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

//頂点aから頂点bまで向かうのにかかるコスト（距離）
//ただし、道が1本道の場合のみ
int cost(int a, int b){
    int c = fabs(b - a);
    return c;
}

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    rep(i, N){
        rep(j, N){
            graph[i][j] = min(cost(i, j), cost(i, X) + cost(j, Y) + 1);
        }
    }
    
    vector<int> cnt(N);
    rep(i, N){
        for(int j = i; j < N; j++){
            cnt[graph[i][j]]++;
        }
    }
    for(int i = 1; i < N; i++) cout << cnt[i] << endl;
    return 0;
}