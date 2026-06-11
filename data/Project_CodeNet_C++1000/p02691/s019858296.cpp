#include <bits/stdc++.h>
#define fir first
#define sec second
#define pb 	push_back
#define ll  long long
#define mp make_pair
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
	ll n;cin>>n;
	ll ans=0;
	map<ll,int>mp;
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		ans+=mp[i-x];
		if(i+x<n) mp[i+x]++;
		//i-j=a[i]+a[j];
	}
	cout<<ans<<endl;
}

// 1  ....... 1
