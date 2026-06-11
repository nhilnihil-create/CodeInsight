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
	std::vector<int> a(n);
	for(auto &i:a)cin>>i;

	sort(a.begin(),a.end());
	vector<int> ct(1004);
	for(int i=0;i<n;i++)ct[a[i]]++;
	for(int i=1;i<=1000;i++)ct[i]+=ct[i-1];
	
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			
			int r=a[i]+a[j];
			auto it=lower_bound(a.begin(),a.end(),r)-a.begin();
			//cout<<"#"<<it<<"\n";
			if(it>j)ans+=(it-j-1);
			
		}

	cout<<ans;

	

}