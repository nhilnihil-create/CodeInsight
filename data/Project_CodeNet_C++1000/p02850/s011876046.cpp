#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<pair<int, int>> vp;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        vp.emplace_back(a, b);
    }

    int k = 0;
    map<pair<int, int>, int> ans;
    vector<int> color(n+1);
    queue<int> q;
    vector<bool> is_checked(n+1, false);
    q.emplace(1);
    is_checked[1] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(k < (int)g[v].size()) k = g[v].size();
        int cur = 1;
        for(auto x : g[v]){
            if(is_checked[x] == false){
                if(cur == color[v]) cur++;
                color[x] = cur;
                ans[make_pair(min(x, v), max(x, v))] = cur;
                cur++;
                is_checked[x] = true;
                q.emplace(x);
            }
        }
    }
    cout << k << endl;
    for(auto p : vp){
        cout << ans[p] << endl;
    }
    return 0;
}