#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int maxn= 1e5+5;
ll a[maxn];
ll n,ans;
ll b[maxn];
ll c[maxn];

int main(){

    cin>>n;
    n++;

    for(int i=1;i<=n;i++) cin>>a[i];
    ans=0;
    b[1]=1;
    c[n]=a[n];
    for(int i=2;i<=n;i++){
        b[i] = (b[i-1]-a[i-1])<<1;
    }
    for(int i=n-1;i>=1;i--) c[i] = c[i+1]+a[i];
    for(int i=1;i<=n;i++) ans+=min(b[i],c[i]);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]){
            flag=1;
            break;
        }
    }
    if(flag) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
