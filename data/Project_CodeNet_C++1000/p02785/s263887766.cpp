#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0; i<n; i++)
     cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(int i=n-k-1; i>=0; i--){
    	ans+=arr[i];
	}
	cout<<ans;
	return 0;
}