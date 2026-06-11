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


	int K,N; cin >> K >> N;
	int m = 0;
	int old = 0;
	int start; cin >> start;
	int goal;
	old = start;
	for (int i = 1; i < N; i++) {
		int a; cin >> a;
		m = max(m, a - old);
		old = a;
		goal = a;
	}
	m = max(m,start + (K - goal));
	cout << K - m << endl;



	return 0;
}
