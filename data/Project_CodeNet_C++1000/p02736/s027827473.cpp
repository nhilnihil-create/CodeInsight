#include <bits/stdc++.h>
using namespace std;

// #define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

/*
 012
0012
1101
2210


5 \in {0,1}
a b c d e
a+b,b+c,c+d,d+e
a+2b+c,b+2c+d,c+2d+e
a+3b+3c+d,b+3c+3d+e
a+4b+6c+4d+e

1
11
101
1111
10001
110011
1010101
11111111
100000001
1100000011
10100000101
111100001111
1000100010001
11001100110011
101010101010101
1111111111111111

*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	char tmp;
	char dummy;
	scanf("%d%c", &N, &dummy);
	debug("N=%d\n", N);
	vector<int> A(N);
	vector<int> B(N - 1);
	for (int i = 0; i < N; i++) {
		scanf("%c", &tmp);
		A[i] = tmp - '0';
		debug("%d ", A[i]);
	}
	debug("\n");
	bool flag_01 = false;
	for (int i = 0; i < N - 1; i++) {
		B[i] = abs(A[i] - A[i + 1]);
		if (flag_01 == false && B[i] == 1) {
			flag_01 = true;
		}
		debug("%d ", B[i]);
	}
	debug("\n");
	if (!flag_01) {
		for (int i = 0; i < N - 1; i++) {
			B[i] /= 2;
		}
	} else {
		for (int i = 0; i < N - 1; i++) {
			B[i] %= 2;
		}
	}

	debug("----01----\n");
	int num = N - 1;  //今何要素か
	int group;
	vector<int> new_B(N - 1);
	while (num > 1) {
		for (int i = 0; i < num; i++) {
			debug("%d ", B[i]);
		}
		debug("\n");

		group = int(exp2(floor(log2(num))));
		debug("group = %d\n", group);
		new_B[0] = 0;
		for (int i = 0; i < group; i++) {
			new_B[0] ^= B[i];
		}
		// debug("%d", new_B[0]);

		for (int i = 1; i < num - group + 1; i++) {
			new_B[i] = new_B[i - 1] ^ B[i - 1] ^ B[i + group - 1];
			// debug("_%d", new_B[i]);
		}
		// debug("\n");

		for (int i = 0; i < num - group + 1; i++) {
			B[i] = new_B[i];
			debug("%d ", B[i]);
		}
		debug("\n");

		num = num - group + 1;
	}

	debug("result:");
	if (flag_01) {
		printf("%d", B[0]);
	} else {
		printf("%d", B[0] * 2);
	}

	return 0;
}