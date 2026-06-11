#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,i;
	cin>>n>>m;
	if(n&1)
		for(i=1;i<=m;i++)
			cout<<i<<" "<<n-i<<endl;
	else
		for(i=0;i<m;i++)
			if(i<(m+1)/2)	cout<<i+1<<" "<<n-i<<endl;
			else			cout<<i+1<<" "<<n-i-1<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}