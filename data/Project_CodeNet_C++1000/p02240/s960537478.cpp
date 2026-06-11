#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

vector<int> G[100000+2];
vector<int> visit(100000+2, -1);
int color = 0;

void dfs(int x){

    if(visit[x] > -1)
        return;
    visit[x] = color;

    for (int i = 0; i < G[x].size(); ++i) {
        dfs(G[x][i]);
    }
}


int main(void) {

    int n,m; cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int s,t; cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    for (int i = 1; i < n; ++i) {
        if(visit[i]<0){
            color++;
            dfs(i);
        }
    }

    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        int s,t; cin>>s>>t;
        if(visit[s]==visit[t]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }

    return 0;
}
