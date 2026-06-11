#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int n,k;cin>>n>>k;
	vector<int> a(n);
	for(int &i:a)cin>>i;
	int sum=accumulate(a.begin(),a.end(),0LL);
	set<int>s;
	for(int i=1;i*i<=sum;i++)if(sum%i==0){s.insert(sum/i);s.insert(i);}
	int ans=1;
	for(int x:s)
	{
		int need=0;
		vector<int> r(n);
		for(int i=0;i<n;i++)r[i]=a[i]%x;
		sort(r.begin(),r.end());
		int tot=accumulate(r.begin(),r.end(),0LL);
		int l=n-tot/x;
		need=accumulate(r.begin(),r.begin()+l,0LL);
		if(need<=k)ans=max(ans,x);
	}
	cout<<ans;
}
