#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	string S;
	scanf("%d", &N);
	cin >> S;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (S.substr(i, 3) == "ABC") {
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}
