#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int P[200100];
	int PMin = 200100;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		// cout << PMin << " " << P[i] << endl;
		if (P[i] <= PMin) ans++;
		PMin = min(PMin, P[i]);
	}
	printf("%d", ans);
	return 0;
}
