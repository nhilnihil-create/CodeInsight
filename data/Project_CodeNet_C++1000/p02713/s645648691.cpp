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

	int K; cin >> K;	


	int sum = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				sum += gcd(i,gcd(j,k));		
			}
		}
	}
	cout << sum << endl;

	return 0;
}
