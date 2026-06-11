#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define fs first
#define sc second

template <class S>
void print(vector<vector<S>> &v) {
  for (ll i = 0; i < (ll)v.size(); i++) {
    for (ll j = 0; j < (ll)v[i].size(); j++) {
      cout << v[i][j] << ' ';
    }
    cout << endl;
  }
}

int n;
int s;
int ans = 0;
int visited[500000];
int memo[500000];
int idx(int x, int y){
    if(x<y) swap(x,y);
    return y * (2*n - y - 1) /2 + x - y - 1;
}

int dfs(int node, vector<vector<int>> &edge) {
    if(visited[node]){
      if (visited[node] == 1) {
        cout << "-1\n";
        exit(0);
      }
      return memo[node];
    }
    visited[node] = 1;
    for(int i: edge[node]){
        memo[node] = max(memo[node], dfs(i, edge)+1);
        ans = max(ans, memo[node]+1);
    }
    visited[node] = 2;
    return memo[node];
}

int main(void){
    cin >> n;
    s = n*(n-1)/2;
    vector<vector<int>> edge(s,vector<int>());
    rep(i,n){
        int par;
        cin >> par;
        rep(j,n-2){
            int chi;
            cin >> chi;
            edge[idx(i,par-1)].push_back(idx(i,chi-1));
            par = chi;
        }
    }
    //print(edge);
    rep(i,s){
        if(!visited[i]){
          dfs(i, edge);
        }
    }
    cout << ans << endl;
}