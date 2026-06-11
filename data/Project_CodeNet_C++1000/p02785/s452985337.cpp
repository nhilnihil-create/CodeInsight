#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int h[N];
int main()
{
	int n,k;
	long long ans=0;
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>h[i];
	sort(h,h+n);
	for(int i=0;i<n-k;++i)
		ans+=h[i];
	cout<<ans<<"\n";
	return 0;
} 