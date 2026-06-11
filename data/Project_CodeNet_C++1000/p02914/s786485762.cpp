#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
ll a[maxn],dig[63];
int vis[63];
void add(ll x){
    for(int i=61;i>=0;i--){
        if(!vis[i]) continue;
        if(x&(1ll<<i)){
            if(dig[i]) x^=dig[i];
            else{
                dig[i]=x;
                break;
            }
        }
    }
}
ll get(){
    ll res=0;
    for(int i=60;i>=0;i--){
        if(vis[i] && ( !(res&(1ll<<i)) ) )
            res^=dig[i];
    }
    return res;
}
int main()
{
    int n;
    ll sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum^=a[i];
    }
    for(int i=0;i<=61;i++){
        if(!(sum&(1ll<<i))) vis[i]=1;
    }
    for(int i=1;i<=n;i++) add(a[i]);
    ll res=get();
    printf("%lld\n",res+(res^sum));
    return 0;
}