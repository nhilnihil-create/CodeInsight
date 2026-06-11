#include <bits/stdc++.h>
using namespace std;
const int N=200009;
typedef long long ll;
ll a[N],d[N];
ll n,k,ans;
bool cmp(const int &x, const int &y) {
    return x>y;
}
bool OK(ll mid) {
    ll i,cnt=0;
    for(i=1;i<=n;i++)
        if(a[i]*d[i]>mid) 
            cnt+=ceil((a[i]*d[i]-mid)/(double)d[i]);
    return cnt<=k;
}
int main() {
	cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    sort(a+1,a+n+1);
    sort(d+1,d+n+1,cmp);
    ll l=0,r=1000000000000,mid;
    while(l<=r) {
        mid=l+(r-l)/2;
        if(OK(mid))
            r=mid-1, ans=mid;
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
