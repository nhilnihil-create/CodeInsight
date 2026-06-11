#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define pb                  push_back
#define arr                 vector<ll>
#define mem(x,val)          memset(x,val,sizeof(x))
#define vp                 vector<pair<ll,ll>>
#define matrix              vector<vector<ll> >
#define digit(x)            floor(log10(x))+1
#define debug(x)            cerr << #x << " is " << x << endl;
#define all(a)              a.begin(),a.end()
#define fixed               setprecision(15)
// ll dx[]={-1,1,0,0},dy[]={0,0,-1,1}; 4 Sides
//ll dx[]={-1,1,-1,1,0,0,-1,1} , dy[]={-1,1,0,0,-1,1,1,-1};    8 Sides
using namespace std;
vector<ll>a[200002];
ll vis[200002];
set<pair<ll, ll>>z;
ll minx = INT_MAX;
ll maxx = INT_MIN;
ll ans;
void dfs(ll node){
    ans++;
    maxx = max(maxx, ans);
    vis[node] = 1;
    for (auto child: a[node]){
        if (!vis[child]){
            
            dfs(child);
        }
    }
}
arr read(ll n){
     arr a;
    for (ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.pb(x);
      }
     return a;
 }
 int main(){
     ll n, m;
     cin>>n>>m;
     for (ll i=0;i<m;i++){
         ll x,y;
         cin>>x>>y;
         if (x > y){
             swap(x, y);
         }
         z.insert({x,y});
     }
     for (auto x:z){
         a[x.first].pb(x.second);
         a[x.second].pb(x.first);
     }
     ll cnt=0;
     for (ll i=1;i<=n;i++){
         if (!vis[i]){
             cnt++;
             ans=0;
             dfs(i);
         }
     }
     cout<<maxx<<endl;
    return 0;
    }
