
#include <iostream>
using namespace std;
const int MAX_N = 110;
struct Card {
	char suit, value;
};

int i, j, minj, n, cnt, k, f;
Card x, a[MAX_N];
void bubbleSort(struct Card A[], int N) {
	for (i = 0; i < N; ++i) {
		for (j = N - 1; j >= i + 1; --j) {
			if (A[j].value < A[j - 1].value) {
				Card x = A[j];
				A[j] = A[j - 1];
				A[j - 1] = x;
			}
		}
	}

}
void selectionSort(struct Card A[], int N) {
	for (i = 0; i < N; ++i) {
		minj = i;
		for (j = i; j < N; ++j) {
			if (A[j].value < A[minj].value) {
				minj = j;
			}
		}

		Card x = A[i];
		A[i] = A[minj];
		A[minj] = x;

	}

}
void print(struct Card A[], int N) {
	for (i = 0; i < N; i++) {
		if (i > 0)
			cout << " ";
		cout << A[i].suit << A[i].value;
	}
	cout << endl;
}
bool hikaku(struct Card C1[], struct Card C2[], int N) {
	for (i = 0; i < N; ++i) {
		if (C1[i].suit != C2[i].suit)
			return false;
	}
	return true;
}

int main() {
	Card C1[MAX_N], C2[MAX_N];
	int N;
	char ch;
	cin >> N;
	for (j = 0; j < N; ++j) {
		cin >> C1[j].suit >> C1[j].value;
	}
	for (i = 0; i < N; ++i) {
		C2[i] = C1[i];
	}

	bubbleSort(C1, N);
	selectionSort(C2, N);

	print(C1, N);
	cout << "Stable" << endl;
	print(C2, N);
	if (hikaku(C1, C2, N) == true)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;

	return 0;
}