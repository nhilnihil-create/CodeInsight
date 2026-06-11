#include <bits/stdc++.h>
#define N 2005
using namespace std;
int n,l[N];
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	sort(l+1,l+n+1);
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			ans+=(lower_bound(l+j+1,l+n+1,l[i]+l[j])-l)-j-1;
	cout<<ans<<endl;
	return 0;
} 