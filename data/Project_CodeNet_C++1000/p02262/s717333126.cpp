#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

int cnt = 0, m = 0;
vector<int> G;

void insertionSort(int A[], int n, int g) {
	for (int i = g; i < n; i++) {
		int v = A[i],
			j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[], int n) {
	for (int j = 1; j <= n; m++, j = j * 3 + 1) {
		G.push_back(j);
	}
	reverse(G.begin(), G.end());
	for (int i = 0; i < m; i++) {
		insertionSort(A, n, G[i]);
	}
}


int main() {
	int n; cin >> n;
	static int A[1000000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	shellSort(A, n);

	cout << m << endl;
	for (int i = 0; i < m; i++) {
		printf("%d", G[i]);
		if (i != m - 1)printf(" ");
		else cout << endl;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}