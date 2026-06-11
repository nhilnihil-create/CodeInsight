#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	int N,M;
	cin >> N >> M;

	vector<int>a(M + 5);
	vector<int>b(M + 5);

	int k = 0, j = 0;

	if (N%2==1) {

		for (int i = 1; i <= M; i++) {
			a[i] = i;
			b[i] = N - i + 1;
			cout << a[i] << ' ' << b[i] << endl;
		}
	}

	else {
		for (int i = 1; i <= (M+1)/2; i++) {
			a[i] = i;
			b[i] = N - i + 1;
			cout << a[i] << ' ' << b[i] << endl;
			k = i;
		}

		for (int i = k+1; i <= M; i++) {
			a[i] = i;
			b[i] = N - i;
			cout << a[i] << ' ' << b[i] << endl;

		}

	}
	return 0;
}