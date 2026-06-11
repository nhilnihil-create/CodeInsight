#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, K;
long long A[200005];
long long memo[200005];

int main(){
	cin >> N >> K;
	rep(i, N) {
		cin >> A[i];
		A[i]--;
	}

	rep(i, N) {
		memo[i+1] = memo[i] + A[i];
		memo[i+1] %= K;
	}

	//num, count
	map<long long, long long> memocount;

	long long ans = 0;
	//iが右端になる
	rep(i, N) {
		memocount[memo[i]]++;
		if(i >= K-1) {
			memocount[memo[i - (K -1)]]--;
		}
		ans += memocount[memo[i+1]];
	}
	cout << ans << endl;
}
