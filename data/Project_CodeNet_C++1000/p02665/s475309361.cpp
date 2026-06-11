#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n,a[max_n];
ll suf[max_n];
ll ans[max_n];
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)scanf("%d",a+i);
    for(int i=n;i>=0;i--)suf[i]=suf[i+1]+a[i];
    ans[0]=1;
    for(int i=1;i<=n;i++){
        //ans[i]=min(ans[i-1]*2)
        ans[i]=min((ans[i-1]-a[i-1])*2,suf[i]);
    }
    for(int i=0;i<=n;i++)if(ans[i]<a[i])return printf("-1\n"),0;
    ll res=0;
    for(int i=0;i<=n;i++)res+=ans[i];
    printf("%lld\n",res);
    return 0;
}