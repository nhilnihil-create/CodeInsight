#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		if(n%i==0)
			x=n/i-1;
		else
			x=n/i;
		for(int j=1;j<=x;j++)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}