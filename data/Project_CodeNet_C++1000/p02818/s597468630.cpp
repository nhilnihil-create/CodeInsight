#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL A, B, K;
	cin >> A >> B >> K;

	if(A+B <= K){
		printf("0 0\n");
		return 0;
	}

	LL d = max(0LL, A - K);
	if(d > 0){
		printf("%lld %lld\n", d, B);
	}
	else{
		printf("%lld %lld\n", 0LL, B - (K - A));
	}
	return 0;
}