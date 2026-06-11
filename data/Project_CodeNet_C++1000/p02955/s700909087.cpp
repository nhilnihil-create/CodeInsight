#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n,a[500],b[500],k,sum,ans;

int main(){
    cin>>n>>k;
    rep(i,n)cin>>a[i],sum+=a[i];
    for(int i=1;i<=sqrt(sum);i++){
        if(sum%i)continue;
        int x=0;
        rep(j,n){
            b[j]=a[j]%i;
            x+=b[j];
        }
        sort(b,b+n);
        x/=i;
        int sum2=0;
        rep(j,n-x)sum2+=b[j];
        if(sum2<=k)ans=max(ans,i);

        int I=sum/i;
        x=0;
        rep(j,n){
            b[j]=a[j]%I;
            x+=b[j];
        }
        sort(b,b+n);
        x/=I;
        sum2=0;
        rep(j,n-x)sum2+=b[j];
        if(sum2<=k)ans=max(ans,I);
    }
    cout<<ans<<endl;
}