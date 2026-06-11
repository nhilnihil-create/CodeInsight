#include<bits/stdc++.h>
using namespace std;
int n,arr[200005],f[1000005],has,cek;
int main()
{
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>arr[i];
		f[arr[i]]++;
		if(arr[i]==1) cek++;
	}
	if(cek==1) 
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int now=arr[i];
		int p=1;
		for(int j=1;j*j<=now;j++)
		{
			if(now%j==0)
			{
				if(j==1) 
				{
					if(f[j]||f[now/j]>1)
					{
						p=0;
						break;
					}
				}
				else if(f[j]||f[now/j])
				{
					p=0;
					break;
				}
			}
		}
		if(p) has++;
	}
	cout<<has<<endl;
}