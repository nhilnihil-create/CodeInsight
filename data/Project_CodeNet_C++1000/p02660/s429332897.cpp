#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

////////////////////////////////////////////////////////////////

int main(void) {
	ll N;
	cin >> N;
	ll tmp_N = N;
	typedef pair<ll, int> P;
	//prime_factors[i].first: 素因数i, second: 素因数iの個数
    vector<P> prime_factors;
	for(ll i=2; i*i<tmp_N; i++){
		ll num = 0;
		if(tmp_N % i != 0) continue;
		while(tmp_N % i == 0){
			tmp_N /= i;
			num++;
		}
		prime_factors.emplace_back(i, num);
	}
	if(tmp_N != 1) prime_factors.emplace_back(tmp_N, 1);
	//cout << "  comp " << endl;
	// vector<ll> divisors;
	// for(int i=0; i<prime_factors.size(); i++){
	// 	for(int j=1; j<=prime_factors[i].second; j++){
	// 		divisors.push_back(j * prime_factors[i].first);
	// 		//cout << prime_factors[i].first << " ";
	// 	}
	// }
	// //cout << "   divisors.size(): " << divisors.size() << endl;
	// sort(divisors.begin(), divisors.end());
	// cout << " divisors: " ; print_vec(divisors);
	// ll ans = 0;
	// for(ll x : divisors){
	// 	if(N % x != 0) continue;
	// 	ans++;
	// 	N /= x;
	// }
	ll ans = 0;
	for(int i=0; i<prime_factors.size(); i++){
		ll cnt = 0;
		while(true){
			cnt++;
			if(prime_factors[i].second - cnt < 0) break;
			prime_factors[i].second -= cnt;
			ans++;
		}
	}
	cout << ans << endl;



}
