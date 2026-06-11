#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t=1;
//	cin>> t;
	while(t--)
	{
		int n,k;
		cin>> n >> k;
		int freq[101]={0};
		while(k--)
		{
			int d;
			cin >> d;
			while(d--)
			{
				int a;
				cin >> a;
				freq[a]++;

			}
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(freq[i]==0)
			{
				count++;
			}
		}
		cout<< count<< endl;
	}
}
