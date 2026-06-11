#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> e(n - 1);
    vector<vector<int>> g(n);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[i] = b;
        g[a].pb(b);
    }
    int k = 0;
    rep(i, n){
        k = max(k, (int)g[i].size());
        if (i == 0) k--;
    }
    k++;
    cout << k << endl;
    queue<int> que;
    vector<int> seen(n);
    que.push(0);
    seen[0] = -1; 
    while (!que.empty()){
        int x = que.front();
        que.pop();
        rep(i, g[x].size()){
            int nx = g[x][i];
            que.push(nx);
            seen[nx] = (seen[x] + i + 1) % k;
        }
    }
    rep(i, n - 1){
        cout << seen[e[i]]  + 1 << endl;
    }
}