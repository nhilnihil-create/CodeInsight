#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 200005;
vector<int> v[MAXN];
bool vis[MAXN];
int cnt=0;
void dfs(int a){
    vis[a]=1;
    for(int i=0;i<v[a].size();i++){
        if(!vis[v[a][i]]){
            cnt++;
             dfs(v[a][i]);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            mx=max(mx,cnt+1);
            cnt=0;
        }
    }
    cout<<mx<<endl;
    
    
    return 0;
}
