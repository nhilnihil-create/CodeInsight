#include<bits/stdc++.h>
using namespace std;

int main(){
	using ll=long long;
	int N;
	cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++){
		cin >> A.at(i);
	}

	vector<vector<ll>> c(60,vector<ll>(2,0));
	for(int i=0; i<N; i++){
		ll tmp=A.at(i);
		bitset<60> bit(tmp);
		for(int j=0; j<60; j++){
			if(bit.test(j)){
				c.at(j).at(1)++;
			}
			else{
				c.at(j).at(0)++;
			}
		}
	}

	ll tmp;
	ll ans=0;
	ll mod=1000000007;
	for(int j=0; j<60; j++){
		tmp = c.at(j).at(0)*c.at(j).at(1)%mod;
		for(int k=0; k<j; k++){
			tmp = tmp*2%mod;
		}
		ans += tmp; 
		ans %= mod;
	}

	cout << ans << endl;

}
