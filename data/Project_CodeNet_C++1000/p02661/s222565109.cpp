#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[214514],b[214514];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	if(n%2)cout<<b[n/2]-a[n/2]+1<<endl;
	else cout<<b[n/2]+b[n/2-1]-(a[n/2]+a[n/2-1])+1<<endl;	
	return 0;
}