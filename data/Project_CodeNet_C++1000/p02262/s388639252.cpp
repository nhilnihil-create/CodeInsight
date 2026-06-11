#include <iostream>
#include <cmath> 
using namespace std;

int insertionSort(int A[], int n, int g)
{
	int cnt = 0;
	for (int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

int main() {
	int A[1000000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> A[i];

	int cnt = 0;
	int m = 0;
	int nn = n;
	int G[100];

	while (nn > 0){
		m++;
		nn = nn/2;
	}

	for (int i = 0; i < m; i++)
	{
		G[i] = pow(2, m - i - 1);
		cnt += insertionSort(A, n, G[i]);
	}

	cout << m << endl;
	for (int i = 0; i < m; i++)
		cout << G[i] << " ";
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << endl;

	return 0;
}
