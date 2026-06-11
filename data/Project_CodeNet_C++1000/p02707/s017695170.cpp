#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n;
	vector<long long int> v[n+1];
	for(int i=0;i<n-1;i++)
	{
		long long x;
		cin>>x;
		v[x].push_back(i+2);
	}
	for(int i=1;i<n+1;i++)
	{
		cout<<v[i].size()<<endl;
	}
	return 0;
}



  
