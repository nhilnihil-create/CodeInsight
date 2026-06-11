#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,k=0;
	string a;
	cin>>n>>a;
	for(int i=0;i<n-2;i++)
	{
		if(a[i]=='A' && a[i+1]=='B' && a[i+2]=='C')
		{
			k++;
		}
	}
	cout<<k;
}