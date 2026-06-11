#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
	ll N;
	cin >> N;

	//素因数分解する
	ll n = N;
	vector<P> vec;//vec[i].first:素因数, second:その素因数の個数
	for(ll i=2; i*i < n; i++){
		ll num = 0;
		while(true){
			if(n%i != 0) break;
			n /= i;
			num++;
		}
		vec.emplace_back(i, num);
	}
	if(n!=1) vec.emplace_back(n, 1);//nが1じゃないならnは素因数となっている(√Nかな)

	// cout << " 素因数分解...:   ";
    // for(int i=0; i<vec.size(); i++){
	// 	for(int j=0; j<vec[i].second; j++){
	// 		cout << vec[i].first << ",  ";
	// 	}
	// }
	// cout << endl;

	ll ans = 0;
	for(int i=0; i<vec.size(); i++){
		ll cnt = 0;
		while(true){
			cnt++;
			if(vec[i].second - cnt < 0) break;
			vec[i].second -= cnt;
			ans++;
		}
	}

	cout << ans << endl;
}
