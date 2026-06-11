#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
const int mod = 1e9+7;
const int N = 1e6+6;
vector<pair<int,int> > v[N];
bool vis[N];
int ans[N],mx;
void dfs(int x, int cl){
    vis[x] = true;
    mx = max(mx,cl);
    int clr = 1;
    for(auto p:v[x]){
        int y = p.fr;
        int id = p.sc;
        if(vis[y])continue;
        if(clr==cl)clr++;
        ans[id] = clr;
        dfs(y,clr);
        clr++;
    }
}
int main(){
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        v[a].pb({b,i});
        v[b].pb({a,i});
    }
    dfs(1,0);
    cout<<mx<<endl;
    for(int i=1;i<n;i++){
        cout<<ans[i]<<endl;
    }
}
