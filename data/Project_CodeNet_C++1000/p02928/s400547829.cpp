#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	ll n,k; cin>>n>>k;
	vector<int> a(n);
	for(auto &i:a) cin>>i;
	ll sum{};
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a.at(i)>a.at(j)) sum++;
		}
	}
	(sum *= k) %= MOD;
	sort(a.begin(),a.end());
	ll low = k*(k-1)/2%MOD;
	for(int i=0; i<n; i++){
		auto it2 = upper_bound(a.begin(),a.end(),a.at(i));
		(sum += (a.end()-it2)*low ) %= MOD;
	}
	cout << sum << endl;
	
}