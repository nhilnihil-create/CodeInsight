#include <iostream>
#include <vector>

using namespace std;
std::vector<int> G;
int cnt;
int A[1000000];

void showArray(int A[], int N){
	for (int p = 0; p < N; p++){
		cout << A[p] << endl;
	}
}

void insertionSort(int A[], int N, int G){
	int key;

	for (int i = G; i < N; i++){
		key = A[i];
		int j = i - G;
		while (j >= 0 && A[j] > key){
			A[j + G] = A[j];
			j = j - G;
			cnt++;
		}
		A[j + G] = key;
	}
}

void shellSort(int A[], int N){
	cnt = 0;
	// make G
	for (int i = 1;;){
		if ( i > N){
			break;
		}
		G.push_back(i);
		i = 3 * i + 1;
	}

	for (int i = G.size(); i > 0; i--){
		insertionSort(A, N, G[i - 1]);
	}
}

int main(){
	int N;

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	shellSort(A, N);

	// ?????????
	cout << G.size() << endl;

	// 2??????
	for (int i = G.size() - 1; i > 0; i--){
		cout << G[i] << " ";
	}
	cout << G[0] << endl;

	// ?????????
	cout << cnt << endl;

	// ?¶????N???
	showArray(A, N);

	return 0;
}