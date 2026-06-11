#include<iostream>
using namespace std;

#define LIM (int)(10e6+1)
bool nprm[LIM];

int main() {
	nprm[0] = nprm[1] = true;
	for (int i = 2; i <= LIM; i++) {
		if (nprm[i] == 0) {
			for (int j = i * 2; j < LIM; j += i) nprm[j] = true;
		}
	}
	while (true) {
		int a, d, n, cnt = 0; cin >> a >> d >> n;
		if (a == 0 && d == 0 && n == 0)break;
		for (int i = a; i < LIM; i += d)	{
			if (nprm[i] == 0)cnt++;
			if (cnt == n) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}