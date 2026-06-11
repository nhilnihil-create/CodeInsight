#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
using namespace std;
ll n,a[maxn],ans;
bool cmp(int aa,int bb){return aa>bb;}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(n&1){
		n=n/2;
		for(int i=1;i<=n;++i)
		ans+=(a[i]*2);
		ans-=a[1];
		ans+=a[n+1];
	}
	else{
		n=n/2;
		for(int i=1;i<=n;++i)
		ans+=(a[i]*2);
		ans-=a[1];
	}
	cout<<ans;
	return 0;
}