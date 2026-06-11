#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 200000;
ll mod = INF;
ll a[maxn+1],b[maxn+1],as[maxn+1],bs[maxn+1];
ll n,m,k;
ll ans=0;

int main(){
    cin >> n>>m>>k;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=m;i++)cin >> b[i];
    as[0]=bs[0]=0;
    for(int i=1;i<=n;i++){
        as[i]=as[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        bs[i]=bs[i-1]+b[i];
    }
    ll aidx=0;
    ll bidx=m;

    for(;aidx<=n;aidx++){
        while(as[aidx]+bs[bidx]>k){
            if(bidx==0)break;
            bidx--;
        }
        if(as[aidx]+bs[bidx]<=k)ans=max(ans,aidx+bidx);
    }

    cout << ans<<endl;
    return 0;
}