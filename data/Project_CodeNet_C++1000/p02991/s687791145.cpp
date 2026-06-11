#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const ll mod = 1e9+7;
ll dp[200003][3];
vector<int>v[200003];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    int s,t;
    cin>>s>>t;
    queue<pair<int,int> > q;
    memset(dp,0x7f,sizeof dp);
    dp[s][0] = 0;
    q.push({s,0});
    while(!q.empty()){
        int x = q.front().first;
        int r = q.front().second;
        q.pop();
        for(int y:v[x]){
            if(dp[y][(r+1)%3]<dp[0][0])continue;
            dp[y][(r+1)%3] = min(dp[y][(r+1)%3],dp[x][r]+1);
            q.push({y,(r+1)%3});
        }
    }
    if(dp[t][0]==dp[0][0]){
        cout<<-1<<endl;
        return;
    }
    cout<<dp[t][0]/3<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
