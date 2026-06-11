#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> ab(m+1);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a > m) continue;
        ab.at(a).push_back(b);
    }
    priority_queue<int> que;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(auto x: ab.at(i)){
            que.push(x);
        }
        if(!que.empty()){
            ans += que.top(); que.pop();
        }
    }
    cout << ans << endl;
}