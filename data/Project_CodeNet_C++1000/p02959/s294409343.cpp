#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ll long long

int main(){
	ll n;
	cin >> n;
	vector<ll> city(n+1);
	vector<ll> hero(n);
	ll num = 0;
	rep(i, n+1){
		cin >> city.at(i);
		num += city.at(i);
	}
	rep(i, n) cin >> hero.at(i);

	ll ans = 0;
	rep(i, n){
		if(city.at(i) <= hero.at(i)){
			hero.at(i)= hero.at(i) - city.at(i);
			city.at(i) = 0;
		}else{
			city.at(i) -= hero.at(i);
			hero.at(i) = 0;
		}

		if(0 < hero.at(i)){
			if(city.at(i+1) <= hero.at(i)) city.at(i+1) = 0;
			else city.at(i+1) -= hero.at(i);
		}
	}

	ll leave = 0;
	rep(i, n+1) leave += city.at(i);

	cout << num-leave << endl;
	return 0;
}
