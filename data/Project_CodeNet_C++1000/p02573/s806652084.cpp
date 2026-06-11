/*
Problem Number: ABC177D
Problem Name: Friends
Notes: 
*/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> g;
vector<bool> v;

int dfs(int n){
    int sum = 1;
    v[n] = 1;
    for(auto ch : g[n])
        if(!v[ch])
            sum += dfs(ch);
    return sum;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    int a, b;
    g = vector<vector<int>>(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    int sol = 0;
    v = vector<bool>(n);
    for(int i = 0; i < n; i++)
        if(!v[i])
            sol = max(sol, dfs(i));

    cout << sol << endl;
    
    return 0;
}