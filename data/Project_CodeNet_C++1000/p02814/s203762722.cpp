#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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


ll GCD(ll a, ll b){
	//if(a < b) std::swap(a, b);//これ入れたらTLEになった
	if(b == 0) return a;
	return GCD(b, a%b);
}

ll LCM(ll a, ll b){
	//return a * b/GCD(a, b);;
	return a/GCD(a, b) * b; //オーバーフローしないように先にgcd(a, b)で割る
}

int num_2(ll x){
	int res = 0;
	while(x%2 == 0){
		res++;
		x /= 2;
	}
	return res;
}

int main(){
	int N;
	ll M;
	cin >> N >> M;
	vector<ll> a(N);
	for(int i=0; i<N; i++) cin >> a[i];
	
	for(int i=0; i<N; i++) a[i] = a[i]>>1;
	for(int i=0; i<N-1; i++){
		if(num_2(a[i]) != num_2(a[i+1])){
			cout << 0 << endl;
			return 0;
		}
	}
	// cout << " a: "; print_vec(a);
	// cout << " num2: " << num_2(a[0]) << endl;
	if(N == 1 ) a.push_back(1);
	ll lcm = LCM(a[0], a[1]);
	for(int i=0; i<N; i++){
		lcm = LCM(lcm, a[i]);
	}
	// cout << " gcd: " << GCD(a[0], a[1]) << " lcm: " << lcm << endl;
	if(lcm > M){
		cout << 0 << endl;
		return 0;
	}

	ll ans = (M/lcm+2-1) /2; // (M/lcm) / 2の切り上げ;
	cout << ans << endl;


}

