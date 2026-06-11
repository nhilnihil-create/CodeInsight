#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
const int mxr= 2e5+1;
vector<pair<int,int>> lef[mxr];
vector<int> righ[mxr];
int main()
{
	//ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);
	int n,x;
	cin>>n;
	vector <int> v;
	int freq[n+1]={};
	for(int i=0; i<n ; i++ )
	{
		cin>>x;
		freq[x]++;
	}
	for(int i = 0; i<=n ; i++)
		if(freq[i])
			v.pb(freq[i]);
	sort(v.begin(),v.end(),greater<int>());
	int len = v.size();
	int sum[len+1]={};
	sum[len-1] = v[len-1];
	sum[len]=0;
	for(int i = len-2 ; i>=0 ; i--)
		sum[i] = v[i]+sum[i+1];
	int ans[n+1];
	cout<<endl;
	for(int i = 1; i<=n ; i++)
	{
		if(i>v.size())
		{
			ans[i]=0;
			continue;
		}
		int l = 0, r=i-1;
		while(l<r)
		{
			int mid = (l+r)/2;
			int del = i-1-mid;
			if(del*v[mid] > sum[mid+1])
			{
				l = mid+1;
			}
			else
				r=mid;

		}
		//cout<<"i = "<<i<<" r = "<<r<<"coeff : "<<(i-1-r)<<"sum : "<<sum[r]<<endl;
		if(r == i-1)
			ans[i] = sum[r];
		else
			ans[i]=  sum[r]/(i-1-r+1);

	}
	for(int i = 1; i<=n ; i++)
	{
		cout<<ans[i]<<' ';
	}

	return 0;
}