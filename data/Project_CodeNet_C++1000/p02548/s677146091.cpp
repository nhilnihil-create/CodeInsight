#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
const ll inf=2e18;
const int mod=998244353;
int n;
bool vis[maxn];
int p[maxn],tot=0;
int st[maxn],top;
void init(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[++tot]=i;
        }

    for(int j=1;j<=tot&&p[j]*i<=n;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int fun(int x){
    int ans=1;
    top=0;
    for(int i=1;p[i]*p[i]<=x;i++){
        if(x%p[i]==0){
            int cnt=0;
            while(x%p[i]==0)cnt++,x/=p[i];
            st[++top]=cnt;
        }
    }
    if(x!=1)st[++top]=1;

    for(int i=1;i<=top;i++)
        ans*=st[i]+1;
    return ans;
}

int main(){
    init(1200);
    cin>>n;
    ll ans=0;
    for(int i=1;i<n;i++){
        ans+=fun(i);
    }
    printf("%lld\n",ans);


    return 0;
}
