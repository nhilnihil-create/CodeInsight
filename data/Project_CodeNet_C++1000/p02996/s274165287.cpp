#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<pair<int,int>> job(n);
	for(int i=0;i<n;i++)cin>>job[i].second>>job[i].first;

	sort(job.begin(),job.end());
	
	int cur=0;
	for(int i=0;i<n;i++)
	{
		cur+=job[i].second;
		if(cur>job[i].first)
		{
			puts("No");return 0;
		}
	}
	puts("Yes");


	
	
}