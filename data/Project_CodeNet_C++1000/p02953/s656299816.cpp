#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;
	vector<ll> H(N);
	rep(i, N) cin >> H[i];

	H[0]--;
	for(ll i = 1; i < N; i++) {
		if(H[i-1] < H[i]) {
			H[i]--;
		} else if (H[i-1] > H[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

}