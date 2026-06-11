#include<bits/stdc++.h>
#define M_PI       3.14159265358979323846
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}

int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		sort(arr,arr+n);
		ll ans=0;
		ans+=arr[n-1];
		ll i=1;
		ll j=n-2;
		ll cur=n-2;
		while(i<=j){
			if(i==j)
				ans+=arr[cur];
			else{
				ans+=2*arr[cur];
			}
			i++;j--;
			cur--;
			//cout<<ans<<"\n";
		}
		cout<<ans;
		
		
		
	}





}
