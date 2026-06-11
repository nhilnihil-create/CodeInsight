#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	ll ans=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++){
			ans+=a[i]*a[j];
		}
	}
	cout<<ans<<"\n";
	return 0;
}