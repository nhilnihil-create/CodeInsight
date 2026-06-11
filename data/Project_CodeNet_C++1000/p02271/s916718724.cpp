#include <iostream>
#include <cstdio>
using namespace std;

int A[2000];
int n;

bool find(int s, int q) {
	if (q == 0)
		return true;
	if (s >= n)
		return false;
	return find(s + 1, q) ||
			find(s + 1, q - A[s]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%d", &A[i]);
	int q;
	scanf("%d", &q);
	int m;
	for (int i = 0; i < q; ++i ) {
		scanf("%d", &m);
		cout << (find(0, m) ? "yes" : "no") << endl;
	}
}