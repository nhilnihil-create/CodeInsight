#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	vector<int>arr1(n+1),arr2(n+1),arr3(n+1);
	for(int i=1; i<=n; i++)
	 cin>>arr1[i];
	for(int i=1; i<=n; i++)
	 cin>>arr2[i];
	for(int i=1; i<n; i++)
	 cin>>arr3[i];
	int ans=0;
	for(int i=1; i<=n; i++){
		ans=ans+arr2[arr1[i]];
	}
	for(int i=2; i<=n; i++){
		if(arr1[i]==arr1[i-1]+1){
			ans+=arr3[arr1[i-1]];
		}
	}
	cout<<ans;
	return 0;
	
}