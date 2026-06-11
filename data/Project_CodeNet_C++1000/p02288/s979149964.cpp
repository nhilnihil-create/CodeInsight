#include <iostream>
using namespace std;

long H;

void maxHeapify(long A[], long i){
	long l = 2 * i;
	long r = 2 * i + 1;

	long largest;
	if (l <= H && A[l] > A[i]){
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= H && A[r] > A[largest]){
		largest = r;
	}

	if (largest != i){
		swap(A[i], A[largest]);
		maxHeapify(A, largest);
	}
}

void buildMaxHeap(long A[]){
	for (long i = H / 2; i > 0; i--){
		maxHeapify(A, i);
	}
}

int main(){
	cin >> H;
	long A[500000];
	for (long i = 1; i <= H; i++){
		cin >> A[i];
	}
	buildMaxHeap(A);
	for (long i = 1; i <= H; i++){
		cout << " " << A[i];
	}
	cout << endl;
	return 0;
}