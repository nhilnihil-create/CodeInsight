#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxm=2e6+5;
//
const int mod=1e9+7;
const int p=1331;
int h[maxm];
int base[maxm];
//
char s[maxm];
int n;
void init(){
    base[0]=1;
    for(int i=1;i<maxm;i++)base[i]=1ll*base[i-1]*p%mod;
    for(int i=1;i<=n;i++){
        h[i]=(1ll*h[i-1]*p+s[i])%mod;
    }
}
int get(int l,int r){
    return (h[r]-1ll*base[r-l+1]*h[l-1]%mod+mod)%mod;
}
bool check(int mid){
    map<int,int>ma;
    for(int i=n;i>=1;i--){
        if(i+mid-1>n)continue;
        int t=get(i,i+mid-1);
        if(ma.count(t)){
            int x=ma[t];
            if(x>i+mid-1)return 1;
        }else{
            ma[t]=i;
        }
    }
    return 0;
}
signed main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    init();
    int ans=0;
    int l=1,r=n/2;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
