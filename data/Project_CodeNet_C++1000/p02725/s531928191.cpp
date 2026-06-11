#include<iostream>
using namespace std;
int main()
{
	int k,n;
	cin>>k>>n;
	int ans=INT_MAX;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
    int arr[2*n];
    for(int i=0;i<n;i++)
    {
    arr[i]=a[i];
    arr[i+n]=k+a[i];	
    }
    for(int i=0;i<=n;i++)
    {
    ans=min(ans,arr[i+n-1]-arr[i]);
    }
    cout<<ans;
}