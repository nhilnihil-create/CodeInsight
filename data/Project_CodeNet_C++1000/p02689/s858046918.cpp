#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=1;
	while(t--)
	{
		int n,m;
		cin>> n >> m;
		vector<long long int>v(n+1);
		for(int i=1;i<=n;i++ )
		{
			cin>> v[i];
		}
		long long int count=0;
		int arr[100005]={0};
        while(m--)
		{
			long long int a,b;
			cin>> a >> b;
			if( v[a]>=v[b])
			{
				arr[b]++;
			}
			if(v[b]>=v[a])
			{
				arr[a]++;
			}

		}

		for(int i=1;i<=n;i++)
		{
			if(arr[i]==0)
			{
				count++;
			}
		}
		cout<< count<< endl;

	}
}
