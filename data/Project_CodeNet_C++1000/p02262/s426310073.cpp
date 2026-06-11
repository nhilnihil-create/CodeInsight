#include <iostream>
#include <vector>
#include <ios>
using namespace std;

int cnt = 0;
void insertionSort(vector<long>& A, int n, int g){
	long i, j, v;
	for (i = g; i < n; ++i){
		v = A[i];
		j = i - g;
		while ( j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j = j - g;
			++cnt;
		}
		A[j + g] = v;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	long n, i, j = 13;
	vector<long> A;

	cin >> n;
	A.resize(n, 0);
	for (i = 0; i < n; ++i)
		cin >> A[i];

	long G[13] = { 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161 };
	for (i = 12; i >= 0; --i){
		if (G[i] >= n){
			j = i;
			continue;
		}

		insertionSort(A, n, G[i]);
	}
	if (0 == j)
		j = 1;

	cout << j << "\n";
	for (i = j - 1; i >= 0; --i){
		cout << G[i];
		if (i != 0)
			cout << " ";
	}
	cout << "\n" << cnt << "\n";

	for (i = 0; i < n; ++i)
		cout << A[i] << "\n";

	return 0;
}