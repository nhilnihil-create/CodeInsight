#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, K;
ll A[505];

bool check(ll num) {
	vector<ll> mod;

	rep(i, N) {
		mod.push_back(A[i]%num);
	}

	sort(mod.begin(), mod.end());

	ll cost = 0;
	ll start = 0;
	ll end = N - 1;
	ll pn = 0;

	//cout << " num = " << num << endl;

	//rep(i, N) {
	//	cout << "mod[" << i << "] = " << mod[i] << endl;
	//}
	
	while(start <= end) {
		//cout << "start = " << start << " end = " << end << " pn = " << pn << " cost " << cost << endl;
		if(pn < 0) {
			pn += mod[start];
			cost += mod[start];
			start++;
		} else {
			if(mod[end] != 0) {
				pn -= (num - mod[end]);
				cost += (num - mod[end]);
			}
			end--;
		}
	}
	//cout << "start = " << start << " end = " << end << " pn = " << pn << " cost " << cost << endl;

	return cost/2 <= K;
}

int main(){

	cin >> N >> K;
	rep(i, N)  cin >> A[i];


	ll sum = 0;
	rep(i, N) sum += A[i];

	vector<ll> divi;
	for(ll i = 1; i * i <= sum; i++) {
		if(sum % i == 0) {
			divi.push_back(i);
			if(i != sum/i) {
				divi.push_back(sum/i);
			}
		}
	}

	ll ans = 1;

	for(ll num: divi) {
		if(check(num)) {
			ans = max(ans, num);
		}
	}
	cout << ans << endl;
}

