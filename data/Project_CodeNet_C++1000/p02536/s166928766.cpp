//Try until you reach your goal
#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define endl "\n"
# define str string
# define vll vector<ll>
# define pb push_back
# define mll map<ll,ll>
# define mp make_pair
# define ff first
# define ss second
# define pll pair<ll,ll>
# define f(x,y) for(int x=0;x<y;x++)
ll x,y;
vector<vector<ll>> v;
vll visited;
ll ans=0;
void dfs(ll p){
    visited[p]=1;
    for(ll j=0;j<v[p].size();j++){
        if(visited[v[p][j]]==0){
            dfs(v[p][j]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>x>>y;
    v.resize(x);
    for(ll i=0;i<y;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    visited.resize(x,0);
    for(ll i=0;i<x;i++){
        if(visited[i]==0){
            ans++;
            dfs(i);
        }
    }
    cout<<ans-1;
    return 0;
}