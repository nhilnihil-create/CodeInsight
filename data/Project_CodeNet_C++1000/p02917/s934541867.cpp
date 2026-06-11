#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=1; i<n; i++)
	 cin>>arr[i];
	for(int i=2; i<n-1; i++)
	{
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
		 arr[i]=max(arr[i-1],arr[i+1]);
	}
	vector<int>ans(n+1);
    ans[1]=arr[1];
    int sum=arr[1];
	for(int i=2; i<n; i++){
		ans[i]=min(arr[i-1],arr[i]);
		sum+=ans[i];
	}
	ans[n]=arr[n-1];
	sum+=ans[n];
	cout<<sum;
	return 0;
	
}