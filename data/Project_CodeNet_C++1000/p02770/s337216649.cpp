#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e5+10;
const int mod=1e9+7;
int d[maxn],a[maxn],z[maxn];
ll sum[maxn];
int k,q,n,x,m,ans,t1,t2;
int main(){
	cin>>k>>q;
	for(int i=0;i<k;i++) cin>>d[i];
	while(q--){
		cin>>n>>x>>m;
		x%=m;
		sum[0]=0;
		z[0]=0;
		for(int i=0;i<k;i++){
			a[i]=d[i]%m;
			sum[i+1]=sum[i]+a[i];
			z[i+1]=z[i]+(a[i]==0);
		}
		t1=(n-1)/k*z[k]+z[(n-1)%k];
		t2=((n-1)/k*sum[k]+sum[(n-1)%k]+x)/m-x/m;
		ans=n-t1-t2-1;
		cout<<ans<<endl;
	}
} 