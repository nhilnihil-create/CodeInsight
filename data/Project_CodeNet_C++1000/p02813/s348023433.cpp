#include <algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int P[8], Q[8];
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &Q[i]);
	}
	int p, q;
	vector<int> series;
	for (int i = 0; i < N; i++) {
		series.push_back(i + 1);
	}
	int order = 1;
	do {
		bool pflag = true, qflag = true;
		for (int i = 0; i < N; i++) {
			if (series[i] != P[i]) pflag = false;
			if (series[i] != Q[i]) qflag = false;
		}
		if (pflag) p = order;
		if (qflag) q = order;
		order++;
	} while (next_permutation(series.begin(), series.end()));
	printf("%d\n", abs(p - q));

	return 0;
}
