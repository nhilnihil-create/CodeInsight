#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int  a[N];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	int ans=0;
	while(n)
	{
		n/=k;
		ans++;
	}
	cout<<ans;
	return 0;
}
