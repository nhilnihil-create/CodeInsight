#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
ll A[200005];
bool ans[200005];

int main(){
	cin >> N;
	rep(i, N) cin >> A[i];

	vector<ll> vec;
	for(ll idx = N; idx >= 1; idx--) {
		ll anum = A[idx - 1];

		ll num = 0;
		for(ll j = 2; j * idx <= N; j++) {
			ll pos = j * idx;
			if(ans[pos]) {
				num += 1;
			}

		}
		
		if(num % 2 != anum) {
			ans[idx] = true;
			vec.push_back(idx);
		}
	}

	cout << vec.size() << endl;
	for(ll i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if(i != vec.size() - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}

}
