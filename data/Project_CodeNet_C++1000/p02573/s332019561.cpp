#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> route[200005];
vector<bool> visited(200005,0);
int s[200005];

void dfs(int v){
    s[v]=0;
    visited[v]=1;
    for(int i:route[v]){
        if (visited[i]==1) continue;
        dfs(i);
        s[v]+=s[i];
    }
    s[v]++;
    return;
}

void testcase(){
    int n ,m ;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        route[a].push_back(b);
        route[b].push_back(a);
    }
    int mx=0;
    for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        dfs(i);
        mx = max(mx, s[i]);
    }
    cout << mx;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1;
  //  cin >> q;
    while(q--){
    testcase();
    }
    return 0;
}

