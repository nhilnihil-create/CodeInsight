#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	string c;
	cin >> c;
	int Rnum = 0;
	for (int i = 0; i < N; i++) {
		if (c[i] == 'R') Rnum++;
	}
	// cout << Rnum << "\n";
	int ans = 0;
	for (int i = Rnum; i < N; i++) {
		if (c[i] == 'R') ans++;
	}

	printf("%d\n", ans);
	return 0;
}
