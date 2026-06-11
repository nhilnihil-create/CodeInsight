#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
ll n,m,k,ans,a[N],b[N],sa[N],sb[N];
int main(){
   	cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i],sa[i]=a[i]+sa[i-1];
    for(int i=1;i<=m;i++)cin>>b[i],sb[i]=b[i]+sb[i-1];
    for(int i=0;i<=n;i++){
        if(sa[i]>k)break;
        ll t=k-sa[i],pos=upper_bound(sb+1,sb+m+1,t)-sb;
        ans=max(ans,i+pos-1);
    }
   	cout<<ans<<endl;
    return 0;
}