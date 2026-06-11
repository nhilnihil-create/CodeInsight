#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

const ll mod = 1000000007;

int main(){
	cin >> N;
	vector<ll> A(N);
	
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
	}
	
	ll result = 0;
	
	// 各ビットを独立に計算する
	for ( ll b = 0; b < 60; b++ ){
		ll bb = (ll)1 << b;
		
		// 立っているビットの累積和
		vector<int> bitacc(N+1);
		int acc = 0;
		for ( int i = 0; i < N; i++ ){
			bitacc[i] = acc;
			if ( A[i] & bb )
				acc++;
		}
		bitacc[N] = acc;
		
		// ΣΣ(ai^aj) を求める
		ll sum = 0;
		for ( int i = 0; i < N-1; i++ ){
			if ( A[i] & bb ){
				sum += (N-1-i) - (bitacc[N] - bitacc[i+1]);
			}
			else {
				sum += bitacc[N] - bitacc[i+1];
			}
		}
		
		//cout << b << " " << bb << " " << sum << endl;
		result += (bb%mod) * (sum%mod);
		result %= mod;
	}
	
	cout << result << endl;
	
	return 0;
}

