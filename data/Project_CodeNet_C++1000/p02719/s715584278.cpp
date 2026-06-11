#include<bits/stdc++.h>
using namespace std;

long long N, K;

int main(){
	cin >> N >> K;

	N = N%K;
	long long ans = N;

	for(long long i = 0; i < 10; i++) {
		N = abs(N - K);
		ans = min(ans, N);
		//cout << "N = " << N << endl;
	}

	cout << ans << endl;

}