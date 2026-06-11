#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

//0 -> 使ってない 1 -> 使った
long long dp[100005][2];

long long cal(vector<long long> p) {
	rep(i, p.size() + 4) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}

	rep(i, p.size()) {
		dp[i+1][0] = max(dp[i][0], dp[i][1]);
		dp[i+1][1] = dp[i][0] + p[i];
	}



	return max(dp[p.size()][0], dp[p.size()][1]);
}

int main(){
	long long N, K, G, C, P;
	string T;
	cin >> N >> K >> G >> C >> P >> T;

	long long ans = 0;
	
	rep(start, K) {
		vector<long long> p;
		char ch = 'x';
		long long cur = start;

		while(cur < N) {
			if(ch == T[cur]) {
				long long num;
				if(ch == 'r') {
					num = P;
				} else if(ch == 's') {
					num = G;
				} else {
					num = C;
				}
				p.push_back(num);
			} else {
				ans += cal(p);
				p.clear();
				ch = T[cur];

				long long num;
				if(ch == 'r') {
					num = P;
				} else if(ch == 's') {
					num = G;
				} else {
					num = C;
				}
				p.push_back(num);
			}

			cur += K;
		}
		ans += cal(p);

	}
	cout << ans << endl;


}
