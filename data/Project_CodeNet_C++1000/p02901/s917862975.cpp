#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=1e5+10;
const ll INF=1e13;
ll dp[(1<<14)],cost[Maxn],item[Maxn];
ll N,M;
bool vis[20];
int main() {
    ios::sync_with_stdio(false);
    cin>>N>>M;
    ll limits=(1<<N)-1;
    for(ll i=1;i<=limits;i++)  dp[i]=INF;
    dp[0]=0;
    for(ll i=1;i<=M;i++){
        ll a,b;
        cin>>a>>b;
        memset(vis,0,sizeof(vis));
        for(ll i=1;i<=b;i++){
            ll c;
            cin>>c;
            vis[c]=1;
        }
        ll temp=0,now=N;
        while(now>0){
            if(vis[now]){
                temp|=1;
            }
            now--;
            temp<<=1;
        }
        temp>>=1;
        cost[i]=a;
        item[i]=temp;
    }
    for(ll i=0;i<=limits;i++){
        for(ll j=1;j<=M;j++){
            ll state=item[j];
            dp[i|state]=min(dp[i|state],cost[j]+dp[i]);
        }
    }
    if(dp[limits]==INF) cout<<"-1";
    else{
        cout<<dp[limits];
    }
    return 0;
}
