#include<bits/stdc++.h>
using namespace std;

string S;
long dp[2020];
long dpnext[2020];

int main(){
	cin >> S;

	long long ans = 0;
	for(long long i = 0; i < ((long long)S.size()); i++) {
		long long num = S[i] - '0';
		for(long long j = 0; j < 2019; j++) {
			dpnext[(j*10+num)%2019] += dp[j];
		}
		dpnext[num] += 1;

		ans += dpnext[0];
		swap(dp, dpnext);
		for(long long j = 0; j < 2019; j++) {
			dpnext[j] = 0;
		}
		
	}
	cout << ans << endl;
}
