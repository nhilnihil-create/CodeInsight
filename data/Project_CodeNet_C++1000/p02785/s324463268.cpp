#include<bits/stdc++.h>
using namespace std;

int main(){
	typedef long long ll;
	ll n,k;
	vector<ll> v;
	ll no = 0;
	cin >> n >> k;
	for(ll i=0;i<n;i++){
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	while(k>0 && v.size()>0){
		v.pop_back();
		k--;
	}
	if(v.empty())cout << 0;
	else{
		for(ll i = 0;i<v.size();i++){
			no+=v[i];
		}
		cout << no;
	}
	return 0;
}