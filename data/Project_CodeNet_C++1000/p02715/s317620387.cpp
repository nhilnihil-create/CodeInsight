#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXK=1e5+69,MOD=1e9+7;
int n,k,ans;
int cnt[MAXK];
int luythua(int x,int y){
    if(y==0)return 1;
    if(y==1)return x;
    int k=luythua(x,y/2);
    return k*k%MOD*luythua(x,y&1)%MOD;
}
signed main(){
    cin>>n>>k;
    for(int i=k;i>=1;i--){
        cnt[i]=luythua(k/i,n);
        for(int j=i*2;j<=k;j+=i)cnt[i]=(cnt[i]-cnt[j]+MOD)%MOD;
        ans=(ans+cnt[i]*i%MOD)%MOD;
    }
    cout<<ans;
}