#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N, d[MAX];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> d[i];
	sort(d, d + N);
	cout << d[N / 2] - d[N / 2 - 1] << endl;
	return 0;
}
