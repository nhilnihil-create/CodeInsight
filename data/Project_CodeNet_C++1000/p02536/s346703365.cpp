/*
   Username : moondancer
   Name : Moon Dancer
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> v[100001];
bool v2[100001];

void dfs(int x){
    v2[x]=1;
    for(int i:v[x]){
        if(!v2[i])
            dfs(i);
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    while( m-- ) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if(!v2[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}