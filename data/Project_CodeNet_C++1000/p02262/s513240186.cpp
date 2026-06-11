#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<int> G;

// 昇順ソート
void insertionSort(vector<int>& A, int n, int g, int& cnt) {
	for (int i = g; i < n; i++) {
		int v = A[i]; // iの示す値を取り出す
		int j = i - g; // とっかえ対象はgだけ離れる

		while (j >= 0 && A[j] > v) { // jの示す値A[j]がiの示す値よりも大きい
			A[j + g] = A[j]; // 押出し
			j = j - g; // またg間隔移動する
			cnt++;
		}

		A[j + g] = v; // 取り出していた値を現在のi位置に戻す
	}
}

int shellSort(vector<int>& A, int n) {
	int cnt = 0;

	// シェルソート間隔数列Gの生成
	for (int h = 1; ;) {
		if (h > n) break;// 要素数分より一段階多く確保する
		G.push_back(h);
		h = 3 * h + 1;
	}

	// 大きい順に使う
	for (int i = G.size() - 1; i >= 0; i--) {
		insertionSort(A, n, G[i], cnt);
	}

	return cnt;
}

int main() {
	int cnt;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	cnt = shellSort(A, N);

	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--) {
		cout << G[i];
		if (i != 0) cout << " ";
	}
	cout << endl;
	cout << cnt << endl;

	for (int i = 0; i < N; i++) {
		cout << A[i] << endl;
	}

	return 0;
}
