#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,h_n;
	long long half = 10000000000;
	cin >> n;
	vector<long long>b(n + 1,0);
	
	for (int i = 1; i <= n; i++) {
		cin >> b.at(i);
		b.at(i) += b.at(i - 1);
	}

	for (int i = 1; i <= n; i++) {
		if (llabs((b[n] - b[i]) - (b[i] - b[0])) < half) {
			half = llabs((b[n] - b[i]) - (b[i] - b[0]));
			h_n = i;
		}
	}
	cout << half << endl;
}
