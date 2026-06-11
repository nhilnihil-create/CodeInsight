#include <bits/stdc++.h>
using namespace std;

int main() {
		string S, T;
		cin >> S >> T;
		int T_len = T.size();
		int S_len = S.size();
		int min_len = T_len;
		int flag = 1;
		for (int i = 0; i<S_len;i++) {
				int count = 0;
				for (int j = 0; j < T_len;j++) {
						if (i + j == S_len) {
								flag = 0;
								break;
						}
						if (S.at(i+j) != T.at(j)) {
								count += 1;
						}
				}
				if (flag == 0) {
						break;
				}
				if (count < min_len) {
						min_len = count;
				}
		}
		cout << min_len << endl;
}