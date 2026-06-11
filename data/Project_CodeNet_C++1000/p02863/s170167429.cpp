#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, T;
//最後の一個をまだつかていない、すでに使ってい流
long long memo[4000][2];
long long A[4000];
long long B[4000];

int main(){
	cin >> N >> T;
	rep(i, N) {
		cin >> A[i] >> B[i];
	}
	rep(i, T + 10) {
		memo[i][0] = -1;
		memo[i][1] = -1;
	}

	memo[0][0] = 0;

	long long ans = 0;
	rep(i, N) {
		for(long long t = T - 1; t >= 0; t--){

			if(memo[t][1] >= 0) {
				//すでにラス一を使っているので t より下に治らないとダメ
				if(t + A[i] < T) {
					memo[t + A[i]][1] = max(memo[t + A[i]][1], memo[t][1] + B[i]);
					ans = max(ans, memo[t + A[i]][1]);
				}
			}

			if(memo[t][0] >= 0) {
				//普通に使う
				if(t + A[i] < T) {
					memo[t + A[i]][0] = max(memo[t + A[i]][0], memo[t][0] + B[i]);
					ans = max(ans, memo[t + A[i]][0]);
				}
				//最後に使う
				memo[t][1] = max(memo[t][1], memo[t][0] + B[i]);
				ans = max(ans, memo[t][1]);

			}
		}
	}
	cout << ans << endl;

}
