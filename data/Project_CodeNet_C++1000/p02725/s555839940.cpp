#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k,n;
	cin>>k>>n;
	vector<ll>arr(n);
	for(int i=0; i<n; i++)
	 cin>>arr[i];
	sort(arr.begin(),arr.end());
	ll dimin=0;
	ll mx=0;
	for(int i=0; i<n-1; i++){
	 dimin+=arr[i+1]-arr[i];
	 mx=max(mx,arr[i+1]-arr[i]);
    }
    dimin+=k-arr[n-1]+arr[0];
    mx=max(mx,k-arr[n-1]+arr[0]);
    cout<<dimin-mx;
    return 0;
}