#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	int N,M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		N -= a;
	}
	if (N < 0) {
		cout << -1 << endl;	
	}else {
		cout << N << endl;
	}

	return 0;
}
