#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>arr(n);
	int sum=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int temp=sum-arr[i];
		ans+=temp*arr[i];
	}
	ans/=2;
	cout<<ans;
	return 0;

}