#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long ll;
const int MAXN = 1000000;

ll cnt;
vector<int> G;

void insertionsort(int *A, int N, int G) {
	for (int i = G; i < N; i++) {
		int v = A[i];
		int j = i - G;
		while (j >= 0 && A[j] > v) {
			A[j + G] = A[j];
			j -= G;
			cnt++;
		}
		A[j + G] = v;
	}
}

void shellsort(int *A, int N) {
	cnt = 0;
	int m = 1;
	do {
		G.push_back(m);
		m = 3 * m + 1;
	} while (m < N&&G.size() <= 100);
	for (int i = G.size() - 1; i >= 0; i--) {
		insertionsort(A, N, G[i]);
	}
}


int main() {
	static int n, A[MAXN];
	cin >> n;
	rep(i, n)cin >> A[i];
	shellsort(A, n);
	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--) {
		if (i != 0)cout << G[i] << " ";
		else cout << G[i] << endl;
	}
	cout << cnt << endl;
	rep(i, n)cout << A[i] << endl;

	return 0;
}
