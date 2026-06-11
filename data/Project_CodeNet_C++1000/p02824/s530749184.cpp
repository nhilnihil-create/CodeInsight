#include<bits/stdc++.h>
using namespace std;
long long n,m,v,p,a[100005],ans,ne[100005];
bool check(int val){
    long long b[100005];
    memcpy(b,a,sizeof(a));
    b[val]+=m;
    long long tot=m*(v-1),big=0;
    for(int i=1;i<=n;i++){
        if(i<val){
            b[i]+=min(m,tot);
            tot-=min(m,tot);
        }
        if(i>val){
            if(b[i]>b[val]){
                b[i]+=min(m,tot);
                tot-=min(m,tot);
                big++;
                continue;
            }
            tot-=min(b[val]-b[i],tot);
            b[i]+=min(b[val]-b[i],tot);
        }
    }
    for(int i=n;i>val;i--)
        if(b[i]<=b[val]&&tot){
            tot-=min(a[i]+m-b[i],tot);
            b[i]+=min(a[i]+m-b[i],tot);
            big++;
        }
    return big<=p-1;
}
int main(){
    cin>>n>>m>>v>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    a[n+1]=1e9+5;
    for(int i=n;i>=0;i--){
        if(a[i+1]!=a[i])
            ne[i]=i;
        else ne[i]=ne[i+1];
    }
    int l=1,r=n+1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=n-mid+1;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<'\n';
}
/*
Damn! I mean, Easy.
*/