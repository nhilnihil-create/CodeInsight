#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	long long N, total, A;
	cin >> N;
	total = 1;
	vector<long long> data(N);
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A != 0) {
			data.at(i) = A;
		}
		else {
			cout << 0 << endl;
			exit(0);
		}
	}
	for (int j = 0; j < N; j++) {
		
		if (total > 1000000000000000000/data.at(j) || total < 0) {
			cout << -1 << endl;
			break;
		}
		else if (total <= 1000000000000000000 && j + 1 < N) {
			total *= data.at(j);
			continue;
		}
		else {
			total *= data.at(j);
			cout << total << endl;
		}
	}
}


