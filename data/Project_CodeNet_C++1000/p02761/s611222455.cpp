#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	map<int, int> input;
	for (int i = 0; i < M; i++) {
		int s, c;
		scanf("%d %d", &s, &c);
		if (N > 1 && s == 1 && c == 0) {
			printf("-1\n");
			return 0;
		}
		if (input.find(s) != input.end() && input[s] != c) {
			printf("-1\n");
			return 0;
		}
		input[s] = c;
	}
	for (int i = 1; i <= N; i++) {
		if (N > 1 && i == 1) {
			if (input.find(1) != input.end()) {
				cout << to_string(input[1]);
			} else {
				cout << 1;
			}
		} else {
			cout << to_string(input[i]);
		}
	}
	cout << endl;

	return 0;
}
