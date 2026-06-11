#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool visited[100005];
vector <int> route[100005];

void dfs(int v){
    visited[v]=1;
    for(int i:route[v]){
        if (visited[i]==1) continue;
        dfs(i);
    }
}

void testcase(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        route[a].push_back(b);
        route[b].push_back(a);
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        dfs(i);
        c++;
    }
    cout << c-1;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q=1;
   // cin >> q;
    while(q--){
    testcase();
    }
    return 0;
}
