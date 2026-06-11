#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);	
}

int main(int argc, char *argv[]) {

	long N,K; cin >> N >> K;

	long d = N % K;

	if (N % K == 0) {
		cout << 0 << endl;
	}else if (d < K / 2){
		cout << d << endl;
	}else if (d < K) {
		cout << K - d << endl;
	}

	return 0;
}
