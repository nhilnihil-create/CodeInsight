#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[1000000];

long long insertionSort(int a[], int n, int g, long long cnt) {
	for (int i = g;i < n;i++) {
		int v = a[i];
		int j = i - g;
		while (j >= 0 && v < a[j])
		{
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}

		a[j + g] = v;
	}

	return cnt;
}


void shellSort(int a[], int n) {
	int idx = 0, m;
	long long cnt = 0;
	int g[20];

	g[0] = 1;
	while (g[idx] <= n) {
		g[++idx] = 3 * g[idx - 1] + 1;
	}

	m = idx;
	cout << m << endl;

	for (int i = idx - 1;0 <= i;i--) {
		cnt = insertionSort(a, n, g[i], cnt);
		cout << g[i];
		if (i == 0) cout << endl;
		else cout << " ";
	}

	cout << cnt << endl;
	for (int i = 0;i < n;i++) {
		cout << a[i] << endl;
	}
}


int main()
{
	cin >> n;

	for (int i = 0;i < n;i++) scanf("%d", &a[i]);

	shellSort(a, n);
    return 0;
}

