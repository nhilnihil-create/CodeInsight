#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	ll times=1;
	// cin>>times;
	while(times--)
	{
		int n;
		cin>>n;
		int start[n],end[n],temp[n];
		for(int i=0;i<n;i++)
			cin>>start[i];
		for(int i=0;i<n;i++)
			cin>>end[i];
		for(int i=0;i<n;i++)
		{
			temp[i]=i+1;
		}
		int s1,s2;
		int count=0;
		do{
			count++;
			int i=0,j=0;
			for(i=0;i<n;i++)
			{
				if(start[i]!=temp[i])
					break;
			}
			if(i==n)
				s1=count;
			for(j=0;j<n;j++)
			{
				if(end[j]!=temp[j])
					break;
			}
			if(j==n)
				s2=count;

		}
		while(next_permutation(temp,temp+n));
		cout<<abs(s2-s1);
	}
}