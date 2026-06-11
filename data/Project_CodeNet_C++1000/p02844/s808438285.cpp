#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
using ll = long long;

bool ans[10][10][10];
bool checked2[10][10];
bool checked[10];
bool completed(int i,int j) {
	for (int p = 0; p < 10; p++) {
		if (!ans[i][j][p])return false;
	}
	return true;
}

int main() {

	int N;
	string S;
	cin >> N >> S;
	int count = 0;
	for (int i = 0; i < N; i++) {
		int a = S[i] - '0';
		if (checked[a])continue;
		checked[a] = true;
		for (int j = i+1; j < N; j++) {
			int b = S[j]-'0';
			if (checked2[a][b])continue;
			checked2[a][b] = true;
			for (int k = j + 1; k < N;k++) {
				int c = S[k]-'0';
				//if (!ans[a][b][c]) {
					ans[a][b][c] = true;
					//count++;
					if (completed(a, b))break;

				//}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (ans[i][j][k])count++;
			}
		}
	}
	cout << count << endl;
}