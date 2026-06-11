#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, L;

int main(){
	cin >> N >> L;
	ll sum = 0;
	for(ll i = 1; i <= N; i++) {
		sum += L + i - 1;
	}


	ll mini = 100000;
	for(ll i = 1; i <= N; i++){
		ll tmp = 0;
		for(ll j = 1; j <= N; j++) {
			if(i == j)continue;
			tmp += L + j - 1;
		}
		if(abs(sum - mini)> abs(sum - tmp)) {
			mini = tmp;
		}
	}

	cout << mini << endl;

}
