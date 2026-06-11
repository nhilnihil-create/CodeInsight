#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());

	ll count=0;

	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			int sum=a[i]+a[j];

			auto it=lower_bound(a.begin(),a.end(),sum);

			if(it==a.end())
			{
				count+=n-j-1;
			}
			else
			{
				int ind=it-a.begin();
				count+=ind-j-1;
			}


		}
	}

	cout<<count<<endl;

	return 0;
}