#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int n, A[MAX_N];

void Out(int k) {
	if (k == 0)
		cout << '[' << A[0] << ']';
	else
		cout << A[0];
	for (int i = 1; i < n; i++) {
		if (k == i)
			cout << ' ' << '[' << A[i] << ']';
		else
			cout << ' ' << A[i];
	}
	cout << endl;
}

int Partition(int p, int r) {
	int x = A[r], i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	Out(Partition(0, n - 1));
	return 0;
}