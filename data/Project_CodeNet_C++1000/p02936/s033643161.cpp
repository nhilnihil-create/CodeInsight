#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> value(n+1);
    vector<vector<int>> G(n+1);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,q){
        int a,b;
        cin >> a >> b;
        value[a] += b;
    }

    queue<int> que;
    que.push(1);
    vector<bool> seen(n+1,false);
    while(que.size() != 0){
        int v = que.front();
        que.pop();
        seen[v] = true;

        for(auto nv : G[v]){
            if(seen[nv]) continue;
            value[nv] += value[v];
            que.push(nv);
        }
    }

    for(int i = 1;i <= n;i++) cout << value[i] << " ";
    cout << endl;

}
