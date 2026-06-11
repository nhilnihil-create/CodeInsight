#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;

int main()
{
    IO
	int n;
	cin>>n;
	int arr[n];
	int arr2[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr2[i]=arr[i];
	}
	sort(arr2,arr2+n);
	int p1=-1,p2=-1,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr2[i]!=arr[i])
		{
			cnt++;
			if(p1==-1)p1=i;
			else p2=i;
		}
	}
	if(cnt==0)
	{
		cout<<"YES"<<endl;
	}
	else if (cnt==2)
	{
		swap(arr[p1],arr[p2]);
		for(int i=0;i<n;i++)
	{
		if(arr2[i]!=arr[i])
		{
			cout<<"NO";
			return 0;
		}
		
	}
	cout<<"YES"<<endl;
	}
	else 
	{
		cout<<"NO"<<endl;
	}


    return 0;
}
