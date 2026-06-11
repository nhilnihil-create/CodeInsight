#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n=s.length();
	int arr[n];
	for(int i=0;i<n;i++)
	arr[i]=0;
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R')
		r=i;
		else
		{
			int cnt=i-r;
			if(cnt%2)
			{
				arr[r+1]++;
			}
			else
			arr[r]++;
		}
	}
	int l=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='L')
		l=i;
		else
		{
			int cnt=l-i;
			if(cnt%2)
			{
				arr[l-1]++;
			}
			else
			arr[l]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}