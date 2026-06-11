#include <iostream>
#include <math.h>
using namespace std;

int insSort(int *a, int n, int g) {
	int j, key, cnt = 0;
	for (int i = g; i < n; i++) {
		key = a[i];
		j = i - g;
		while(( j >= 0) && (a[j] > key)) {
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = key;
	}
	return cnt;
}

int main(){
	int n, m, cnt=0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (m = 1; m < n + 2; m++) {
		if ((pow( 3 , m ) -1) / 2 > n) {
			m = m - 1;
			break;
		}
	}
	int *g = new int[m];
	for (int i = 0; i < m; i++ ) {
		g[i] = (pow(3, m - i) -1) / 2;
		cnt += insSort(a, n, g[i]);
	}
	cout << m << endl;
	for (int i = 0; i < m - 1; i++ )
		cout << g[i] << ' ';
	cout << g[m - 1] << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}