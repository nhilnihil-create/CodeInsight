#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	if (N % 2 == 1) {
		printf("No\n");
		return 0;
	}
	char s[110];
	scanf("%s", s);

	bool ans = true;
	for (int i = 0; i < N / 2; i++) {
		// cout << s[i] << endl;
		if (s[i] != s[N / 2 + i]) {
			ans = false;
			break;
		}
	}

	printf(ans ? "Yes" : "No");

	return 0;
}
