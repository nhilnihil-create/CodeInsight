#include<bits/stdc++.h>
using namespace std;
 
int main() {
	long long k,n,m;
	cin>>n>>m>>k;
	
	vector<long long> arr1(n+2,0);
	vector<long long> arr2(m+2,0);
	
	for(int i=1;i<=n;i++)
	{
	    cin>>arr1[i];
	    arr1[i]+=arr1[i-1];
	}
	
	for(int i=1;i<=m;i++)
	{
	    cin>>arr2[i];
	    arr2[i]+=arr2[i-1];
	}
	
	int j=m,ans=0;
	
	for(int i=0;i<=n;i++)
	{
	    if(arr1[i]>k)
	    break;
	    while(arr2[j]>(k-arr1[i]))
	    j--;
	    
	    ans=max(ans,(i+j));
	}
	cout<<ans;
	return 0;
}