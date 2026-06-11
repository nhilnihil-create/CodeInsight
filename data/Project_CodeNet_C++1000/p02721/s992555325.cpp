#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;


int32_t main()
{
	int n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	
	vector<int> a,b;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
		a.push_back(i),i=i+c;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='o')
		b.push_back(i),i-=c;
	}
	
	for(int i=0;i<k;i++)
	{
		if(a[i]==b[k-1-i])cout<<a[i]+1<<'\n';
	}
	
}