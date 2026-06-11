#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin>>n;
	vector<int>ans(n+1);
	for(int i=1; i<=100; i++)
	{
		for(int j=1; j<=100; j++)
		{
			for(int k=1; k<=100; k++)
			{
				m=(i*i)+(j*j)+(k*k)+(i*j)+(j*k)+(k*i);
				if(m<=n)
				ans[m]++;
				else
				break;
			}
		}
	}
	for(int i=0; i<n; i++)
	cout<<ans[i+1]<<"\n";
	return 0;
}
