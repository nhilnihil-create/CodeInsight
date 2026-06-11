#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long int;

int main() {
	LL N, M;
	cin >> N >> M;
	LL l = 1, u = N;
	int m = 0;
	if (N % 2 == 1) {
		while (m < M) {
			cout << l << " " << u << endl;
			m++;
			l++;
			u--;
		}
	}
	else {
		l = 1;
		bool over_half = false;
		while (m < M) {
			if ((u - l) * 2 <= N && over_half == false) {
				over_half = true;
				u--;
			}
			cout << l << " " << u << endl;
			m++;
			l++;
			u--;
			

		}


	}
	return 0;

}