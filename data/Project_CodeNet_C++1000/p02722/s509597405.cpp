#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

bool hantei(long long x){
	for(long long i=2; i*i<=x; i++){
		if(x%i==0) return 0;
	}
	return x>1;
}

vector<ll> bunkai(ll x){
	vector<ll> a;
	if(hantei(x)) {
		a.push_back(x);
		a.push_back(1);
	}
	else{
		for(ll i=1; i*i<=x; i++){
			if(!(x%i)) {
				a.push_back(i);
				if(i*i==x) break;
				a.push_back(x/i);
			}
		}
	}
	sort(a.begin(),a.end());
	return a;
}
int main(){
	
	ll n; cin>>n;
	auto a = bunkai(n-1);
	auto b = bunkai(n);
	ll ans{};
	for(auto i:b){
		ll m = n;
		if(i==1) continue;
		while(!(m%i)) m/=i;
		ans += ((m%i)==1);
	}
	ans += a.size()-1;
	cout << ans << endl; 
	
}

