#include<iostream>
#include<vector>
using namespace std;

long cnt;
vector<int> G;

void insertionSort(int A[], int N, int g) {
	for (int i = g; i < N; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && v < A[j]) {
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(int A[], int N) {
	for (int i = 1; ; ) {
		if (i > N) break;
		G.push_back(i);
		i = 3*i + 1;
	}
	
	for (int i = G.size() - 1; i >= 0; i--) {
		insertionSort(A, N, G[i]);
	}
}
	
int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cnt = 0;
	
	shellSort(A, N);
	
	cout << G.size() <<endl;
	for (int i = G.size() - 1; i > 0; i--) {
		cout << G[i] << " ";
	}
	cout << G[0] << endl;
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		cout << A[i] << endl;
	}
	
	return 0;
}