#include<bits/stdc++.h>

using namespace std;
int arr[200005];

bool isvalid(int m,int n,int k)
{
	if(m==0) return false;
	long long total=0;
	for(int i=0;i<n;i++)
	{
		total+=(arr[i])/m;
		if(arr[i]%m==0) total--;
	}

	if(total<=k) return true;
	return false;
}

void solve(int n,int k)
{
	int i=0,j=1000000001;
	while(i<j)
	{
		int mid=(i+j)/2;
		if(isvalid(mid,n,k))
			j=mid;

		else
			i=mid+1;
	}

	cout<<i;
}

int main()
{
	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>arr[i];

	solve(n,k);

	return 0;
}