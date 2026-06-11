#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	ll m;
	ll lcm=1;
	cin>>n>>m;
    vector<ll>arr(n);
	for(int i=0; i<n; i++)
	 cin>>arr[i];
	for(int i=0; i<n; i++){
		lcm=(lcm*arr[i])/(__gcd(lcm,arr[i]));
	}
	int flag=0;
	for(int i=0; i<n-1; i++){
		ll num1=arr[i];
		ll num2=arr[i+1];
		int cnt1=0,cnt2=0;
		while(num1%2==0){
			num1/=2;
			cnt1++;
		}
		while(num2%2==0){
			num2/=2;
			cnt2++;
		}
		if(cnt1!=cnt2){
			flag=1;
			break;
		}
	}
	if(flag)
	 cout<<"0";
	else{
		ll ans=(2*m/lcm+1)/2;
		cout<<ans;
	
	}
	return 0;
	
}