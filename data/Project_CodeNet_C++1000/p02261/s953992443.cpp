#include <iostream>
#include <algorithm>

using namespace std;

int cntSort;

void printArray(char B[], int A[], int N) {
	for (int i = 0; i < N - 1; i++)
		cout << B[i] << A[i] << " ";
	cout << B[N - 1] << A[N - 1] << endl;
}

void insertionSort(int A[], char B[], int N) {
	for (int i = 1; i < N; i++) {
		int val = A[i];
		char cval = B[i];
		int j = i - 1;
		while (j >= 0 && A[j] > val) {
			A[j + 1] = A[j];
			B[j + 1] = B[j];
			j--;
		}
		A[j + 1] = val;
		B[j + 1] = cval;
	}
}

void bubbleSort(int A[], char B[], int N) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; i < j; j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
				swap(B[j - 1], B[j]);
			}
		}
	}
}

void selectionSort(int A[], char C[], int N) {
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		swap(A[minj], A[i]);
		swap(C[minj], C[i]);
	}
}

void isStable(char A[], char B[], int N) {
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]){
			cout << "Not stable" << endl;
			return;
		}
	}
	cout << "Stable" << endl;
	return;
}

int main() {
	//??\???---------------------------------------
	int N;
	cin >> N;
	char Cbub[N];
	char Csel[N];
	char Cins[N];
	int Abub[N];
	int Asel[N];
	int Ains[N];
	for (int i = 0; i < N; i++) {
		cin >> Cbub[i];
		Csel[i] = Cbub[i];
		Cins[i] = Cbub[i];
		cin >> Abub[i];
		Asel[i] = Abub[i];
		Ains[i] = Abub[i];
	}

	//?????????-------------------------------------
	selectionSort(Asel, Csel, N);
	bubbleSort(Abub, Cbub, N);
	insertionSort(Ains, Cins, N);

	//????????§???????¨?-------------------------------
	printArray(Cbub, Abub, N);
	isStable(Cbub, Cins, N);
	printArray(Csel, Asel, N);
	isStable(Csel, Cins, N);
}