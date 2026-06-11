#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define popb pop_back
#define all(A) A.begin(),A.end()
#define mod 1000000007
using namespace std;
int main() {
	int n;
	ll a=0,b=0,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]) a++;
			if(arr[i]>arr[j]) b++;
		}
	}
	ll ans=(k*(k-1))/2;
	ans%=mod;
	ans*=a+b;
	ans%=mod;
	ans+=(k*b)%mod;
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}