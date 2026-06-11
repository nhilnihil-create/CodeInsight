#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
#define endl "\n"

int main()
{	
	FIO;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll n;
	cin>>n;

	ll ans = 1, minus = 0;
	vector<ll> arr(n);

	for(ll i=0;i<arr.size();i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	
	if(arr[0] == 0){
		cout<<0<<endl;
		return 0;
	}

	for(ll i=0;i<n;i++){
		// ll val;
		// cin>>val;
		// ll check =ans*arr[i]; 
		if( arr[i]<= 1000000000000000000/ans){
			ans *= arr[i];
			
		}
		else{
			cout<<-1<<endl;
			return 0;
		}
		
	}

	cout<<ans<<endl;

	
	return 0;
	
}