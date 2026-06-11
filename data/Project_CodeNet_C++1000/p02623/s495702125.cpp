#include <bits/stdc++.h>
using namespace std;

int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	long long n,m,k;
	cin>>n>>m>>k;

	vector<long long>a(n+1),b(m+1);
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];

	for(int i=1;i<=n;i++)
		a[i] += a[i-1];

	for(int i=1;i<=m;i++)
		b[i] += b[i-1];	

	int cnt =0;

	for(int i=0;i<=n;i++)
	{
		long long rem = k - a[i];

		if(rem>=0)
		{
			auto l = lower_bound(b.begin(),b.end(),rem);
			int idx = l-b.begin();
			if(idx>m || b[idx]>rem)
				idx--;

			cnt = max(cnt,i+idx);

		}
	}
	cout<<cnt<<"\n";
    return 0;
		
}