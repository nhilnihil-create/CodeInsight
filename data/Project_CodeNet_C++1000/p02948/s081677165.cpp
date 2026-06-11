#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > V(M+1);
    rep(i, N){
        int a, b; cin >> a >> b;
        if(a > M)continue;
        V[a].push_back(b);
    }
    priority_queue<int> q;
    int ans = 0;
    for (int i = 1; i <= M; i++){
        rep(j, V[i].size()){
            q.push(V[i][j]);
        }
        if(!q.empty()){
            int x = q.top(); q.pop();
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}