#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int> que;
    vector<vector<int>> ba(100005);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        ba[a].emplace_back(b);
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(auto p : ba[i]) que.push(p);

        if(que.empty()) continue;
        int t = que.top();
        que.pop();
        ans += t;

    }
    cout << ans << endl;
}