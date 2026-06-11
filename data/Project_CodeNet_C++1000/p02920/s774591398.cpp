#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	cin >> N;
	ll num = (1<<N);
	vector<ll> S(num);
	rep(i, num) cin >> S[i];

	sort(S.rbegin(), S.rend());
	vector<ll> next;
	next.push_back(S[0]);


	map<ll, ll> memo;
	set<ll> numset;

	rep(i, S.size()) {
		memo[S[i]]++;
		numset.insert(S[i]);
	}


	rep(_, N) {
		vector<ll> vec = next;
		for(ll n: vec) {
			set<ll>::iterator it = numset.lower_bound(n);
			if(it == numset.begin()) {
				cout << "No" << endl;
				return 0;
			}
			it--;
			ll newnum = *it;
			next.push_back(newnum);
			memo[newnum]--;
			if(memo[newnum] == 0) {
				memo.erase(newnum);
				numset.erase(newnum);
			}
		}
	}
	cout << "Yes" << endl;
}
