#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int main(int argc, char *argv[]) {

	int N; cin >> N;

	vector<int> X(N,0);
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}

	int MIN = INF;
	for (int i = 1; i <= 100; i++) {
		int hp = 0;
		for (int j = 0; j < N; j++) {
			hp += (X[j]-i) * (X[j] - i);
		}
		MIN = min (hp,MIN);
	}
	cout << MIN << endl;

	return 0;
}
