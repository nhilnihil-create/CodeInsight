#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll a[N],p[69],n,sum,res;
void insert(ll x){
    for(int i=60;i>=0;i--)if(x&(1ll<<i)){
        if(!p[i]){p[i]=x;break;}
        x^=p[i];
    }
}
void solve(){
    for(int i=60;i>=0;i--){
        if(res+(res^sum)<(res^p[i])+(res^p[i]^sum))res^=p[i];
    }
}
int main(){
  //  freopen("tt.in","r",stdin),freopen("tt.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum^=a[i];
    for(int i=0;i<60;i++)if(sum&(1ll<<i)){
        for(int j=1;j<=n;j++)if(a[j]&(1ll<<i))a[j]^=(1ll<<i);
    }
    for(int i=1;i<=n;i++)insert(a[i]);
    solve();
    cout<<res+(res^sum)<<endl;
    return 0;
}