#include <iostream>
#include <vector>
using namespace std;

const long INFTY = 1000000001;
long cnt = 0;

void merge(long A[], long left, long mid, long right){
	long n1 = mid - left;
	long n2 = right - mid;
	vector<long> L(n1 + 1), R(n2 + 1);
	for (long i = 0; i < n1; i++) L[i] = A[left + i];
	for (long i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = INFTY;
	R[n2] = INFTY;
	long i = 0;
	long j = 0;
	for (long k = left; k < right; k++){
		cnt++;
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(long A[], long left, long right){
	if (left + 1 < right){
		long mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	long n, S[500000];
	cin >> n;
	for (long i = 0; i < n; i++) cin >> S[i];
	mergeSort(S, 0, n);
	for (long i = 0; i < n; i++){
		if (i) cout << " ";
		cout << S[i];
	}
	cout << endl << cnt << endl;
	return 0;
}