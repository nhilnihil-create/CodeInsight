#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;cin>>n;
	int a[n];
	map<int,int>m;
	for(int i=0;i<n;i++) cin>>a[i],m[a[i]]++;
	sort(a,a+n);
	ll ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			// cout<<a[i] <<" "<<a[j] <<" "<< lower_bound(a+j+1,a+n,a[i]+a[j])-a<<"\n";
			// cout<<(upper_bound(a+j+1,a+n,a[i]+a[j])-a)-j-1-m[a[i]+a[j]]<<"\n";
			ans+=(upper_bound(a+j+1,a+n,a[i]+a[j])-a)-j-1-m[a[i]+a[j]];
		}
	}
	cout<<ans<<"\n";
	return 0;
}