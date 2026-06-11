#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> L;
	int ans = 0;

	for (int i=0; i<N; i++) {
		int t;
		cin >> t;
		L.push_back(t);
	}

	for (int i=0; i<N-2; i++) {

		for(int j=i+1; j<N-1; j++){
			for (int k=j+1; k<N; k++) {
				int a = L.at(i); int b = L.at(j); int c = L.at(k);
				if (a == b|| a == c || b == c) {
				} else {
					if (a + b > c && a+c>b && b+c>a) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}