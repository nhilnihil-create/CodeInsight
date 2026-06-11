#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<double>arr(n);
    for(int i=0; i<n; i++)
     cin>>arr[i];
    for(int i=0; i<n; i++)
    {
    	arr[i]=(arr[i]+1)/2;
	}
	double sum=0;
	for(int i=0; i<k; i++)
	{
		sum+=arr[i];
	}
	double ans=sum;
    for(int i=k; i<n; i++){
    	sum=sum-arr[i-k];
    	sum+=arr[i];
    	ans=max(ans,sum);
	}
	cout<<fixed<<setprecision(8)<<ans;
	return 0;
}