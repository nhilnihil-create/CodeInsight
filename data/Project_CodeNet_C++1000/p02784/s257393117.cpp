#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h,n;
	cin>>h>>n;
	vector<int>arr(n);
	ll sum=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum>=h)
	 cout<<"Yes";
	else
	 cout<<"No";
	return 0;
	
}