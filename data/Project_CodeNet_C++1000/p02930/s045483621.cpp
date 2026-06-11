#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;


int main() {
	int N; cin >> N;
	rep (i, N) {
		for (int j = i + 1; j < N; j++) {
			
			for (int k = 0; true; k++) {
				if (((i >> k) & 1) != ((j >> k) & 1)) {
					cout << k + 1 << " ";
					break;
				}
			}
		}
		cout << endl;
	}

}