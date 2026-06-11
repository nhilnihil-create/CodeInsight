#include<bits/stdc++.h>
#define MAX 300
#define MOD 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,n;
	cin>>k>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)	
		cin>>v[i];
	int ans = INT_MAX;
	for(int i=0;i<n;++i)
	{
		int dist = v[n-1]-v[i];
		if(i)
			dist += k-v[n-1]+v[i-1];
		ans = min(ans,dist);
	}
	cout<<ans<<endl;
	return 0;
}