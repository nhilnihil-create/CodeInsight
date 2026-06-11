#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
const int mod=1e9+7;

ll a[N],b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k,x,ans=0;
    cin>>n>>m>>k;
    ll sum=0;
    for(int i=1;i<=n;i++){
    	cin>>x;
    	sum+=x;
    	a[i]=sum;
    }
    sum=0;
    for(int i=1;i<=m;i++){
    	cin>>x;
    	sum+=x;
    	b[i]=sum;
    }
    ans=0;
    for(int i=0;i<=n;i++){
    	ll c=k;
    	if(a[i]>c)continue;
    	c-=a[i];
    	ll l=0,r=m,ok;
    	while(l<=r){
    		int mid=(l+r)/2;
    		if(b[mid]<=c){
    			ok=mid;
    			l=mid+1;
    		}
    		else {
    			r=mid-1;
    		}
    	}
    	ans=max(ans,i+ok);
    }
    cout<<ans<<'\n';
}
