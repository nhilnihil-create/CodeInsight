#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;

// (head, tail) -> count
map<pair<long long, long long>, long long> memo;

int main(){
	cin >> N;
	rep(i, N+1) {
		string S = to_string(i);
		long long head = S[0] - '0';
		long long tail = S[S.size() - 1] - '0';
		if(head != 0 && tail != 0) {
			memo[make_pair(head, tail)]++;
		}
	}

	long long ans = 0;
	for(long long head = 1; head < 10; head++) {
		for(long long tail = 1; tail < 10; tail++) {
			ans += memo[make_pair(head, tail)] * memo[make_pair(tail, head)];
		}
	}
	cout << ans << endl;
}
