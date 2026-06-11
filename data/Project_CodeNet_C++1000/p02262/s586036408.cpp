#include <iostream>
#include <vector>

using namespace std;

void printa_rf(int A[], int len) {
	for (int i = 0; i < len; i++)
		cout << A[i] << endl;
}

void printa_space(vector<int> A, int len) {
	cout << A[0];
	for (int i = 1; i < len; i++)
		cout << " " << A[i];
	cout << endl;
}

int insertionSort(int A[], int len, int g) {
	int cnt = 0;
	for (int i = g; i < len; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
	return cnt;
}

vector<int> makeG(int len) {
	vector<int> G;
	int h = 1;
	G.push_back(h);
	while ((h = 3 * h + 1) < len) {
		G.insert(G.begin(), h);
	}
	return G;
}

void shellSort(int A[], int len) {
	int cnt = 0;
	vector<int> G = makeG(len);
	int m = G.size();
	for (int i = 0; i < m; i++)
		cnt += insertionSort(A, len, G[i]);
	cout << m << endl;
	printa_space(G, m);
	cout << cnt << endl;
	printa_rf(A, len);
}

int main() {
	int n, *a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	shellSort(a, n);
	delete[] a;
	return 0;
}