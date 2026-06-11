#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;
using vd = vector<double>;

int main(){
	ll N;
	cin >>N;
	ll ans = 1e12;
	for(ll i = 1; i*i <= N; i++){
		if(N%i == 0){
			ans = min(ans, (N/i + i));
		}
	}
	cout << ans-2 << endl;
}
