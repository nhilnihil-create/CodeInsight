#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const ll N=1e7+10;
ll d[N],num[N],prime[N]; //sd是约数和
bool vis[N];
void fun(){
    memset(vis,0,sizeof(vis));
    num[1]=1;
    d[1]=1;
    prime[0]=0;
    for(ll i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[++prime[0]]=i;
            d[i]=1;
            num[i]=2;
        }
        for(ll j=1;j<=prime[0]&&i<=N/prime[j];j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                d[i*prime[j]]=d[i]+1;
                num[i*prime[j]]=num[i]/(d[i]+1)*(d[i]+2);
                break;
            }
            d[i*prime[j]]=1;
            num[i*prime[j]]=num[i]*2;
        }
    }
}
int main() {
    fun();
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=i*num[i];
    }
    cout<<ans;
    return 0;
}
