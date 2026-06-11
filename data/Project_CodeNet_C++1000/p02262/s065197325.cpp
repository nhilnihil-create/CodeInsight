#include <iostream>

#define N_SIZE 1000000
#define M_SIZE 100

using namespace std;

int insertionSort(int[], int, int);
void shellSort(int[], int);

int main(void) {
	int n;
	static int list[N_SIZE];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	shellSort(list, n);

	for (int i = 0; i < n; i++) {
		cout << list[i] << "\n";
	}

	cin >> n;

	return 0;
}

int insertionSort(int list[], int n, int g) {
	int v, j, cnt = 0;
	for (int i = g; i < n; i++) {
		v = list[i];
		j = i - g;
		while (j >= 0 && list[j] > v) {
			list[j + g] = list[j];
			j = j - g;
			cnt++;
		}
		list[j + g] = v;
	}
	return cnt;
}

void shellSort(int list[], int n) {
	int m, i = 0, cnt = 0;
	int glist[M_SIZE];
	
	glist[0] = 1;
	while (++i) {
		int tmp = glist[i - 1] * 3 + 1;
		if (tmp >= n || i >= M_SIZE-1) {
			m = i;
			break;
		}
		else {
			glist[i] = tmp;
		}
	}

	cout << m << "\n";
	for (int i = m - 1; i >=0; i--) {
		if (i < m-1) {
			cout << " ";
		}
		cout << glist[i];
	}
	cout << "\n";

	for (int i = m - 1; i >= 0; i--) {
		cnt += insertionSort(list, n, glist[i]);
	}
	cout << cnt << "\n";
}