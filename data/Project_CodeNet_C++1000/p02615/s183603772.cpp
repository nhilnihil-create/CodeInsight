#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
	io;
	ll n;
	cin>>n;
	vector<ll>v(n);
	for(ll i=0;i<n;i++)cin>>v[i];
	sort(v.rbegin(),v.rend());
	ll s=0;
	s+=v[0];
	ll idx=1,cnt=0;
	for(ll i=2;i<n;i++){
		s+=v[idx];
		cnt++;
		if(cnt==2){
			cnt=0;
			idx++;
		}
	}cout<<s;
	return 0;
}