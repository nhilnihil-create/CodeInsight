#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<ll>v[200005];
bool visited[200005] = {false};

ll dfs(ll p){
    queue<ll>q;
    q.push(p);
    visited[p]=true;
    ll count=0;
    while(!q.empty()){
        ll i;
        ll p1=q.front();
        q.pop();
        for(i=0;i<v[p1].size();i++){
            if(visited[v[p1][i]]==false){
                visited[v[p1][i]]=true;
                count++;
                q.push(v[p1][i]);
            }
        }
    }
    return count+1;
}

void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    boost();
    ll n,m;
    cin >> n >> m;
    ll i;
    for(i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll ans=dfs(1);
    for(i=1;i<=n;i++){
        if(visited[i]==false){
            ll d=dfs(i);
            ans=max(ans,d);
        }
    }
    cout << ans << endl;
}