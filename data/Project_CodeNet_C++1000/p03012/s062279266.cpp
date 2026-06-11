#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,w,a[101],ans=101;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w;
		if(i)a[i]=a[i-1]+w;
		else a[0]=w;
	}
	for(int i=0;i<n;i++)
	{
		int s1=a[i];
		int s2=a[n-1]-a[i];
		ans=min(ans,abs(s1-s2));
	}
	cout<<ans<<endl;
    return 0;
}
