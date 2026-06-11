#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];
int G[30] = { 536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,
1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1 };
int cnt, m;


void show(int n) {
	cout << m << endl;
	for (int i = 30 - m; i < 30; i++) {
		cout << G[i];
		if (i < 30 - 1)
			cout << " ";
	}
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

void insertionSort(int n,int g) {
	int j, v;
	for (int i = g; i < n; i++) {
		v = arr[i];
		j = i - g;
		while (j >= 0 && arr[j] > v) {
			arr[j + g] = arr[j];
			j -= g;
			cnt++;
		}
		arr[j + g] = v;
	}
}

void shellSort(int n) {
	cnt = 0;
	int i = 0;
	while (G[i] > n)i++;
	m = 30-i;
	for (; i < 30; i++)
		insertionSort(n, G[i]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	shellSort(n);

	show(n);

	return 0;
}