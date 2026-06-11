#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>&add,vector<vector<int>>&g,vector<int>&ans,vector<bool>&find,int s){
    ans[s] += add[s];
    find[s] = 1;
    for(int i = 0;i < g[s].size();i++){
        if(find[g[s][i]])
            continue;
        ans[g[s][i]] = ans[s];
        dfs(add,g,ans,find,g[s][i]);
    }
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<vector<int>>v(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>ans(n + 1,0);
    vector<int>add(n + 1,0);
    vector<bool>find(n + 1,false);
    for(int i = 0;i < q;i++){
        int p,x;
        cin >> p >> x;
        add[p] += x;
    }
    dfs(add,v,ans,find,1);
    for(int i = 1;i < n + 1;i++){
        cout << ans[i] << " ";
    }
}