#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	int N; cin >> N;

	double sum = 0;
	for (int i = 0; i < N; i++) {
		double a; cin >> a;
		a = 1 / a;
		sum += a;
	}
	cout << setprecision(10) << 1 / sum << endl;

	return 0;
}
