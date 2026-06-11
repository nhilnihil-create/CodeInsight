#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	int A[N];
	for (int i=0; i<N; i++){
	    cin >> A[i];
	}
	sort(A, A+N);
	int MAX=0;
	for (int i=0; i<N-1; i++){
	    MAX=max(MAX,A[i+1]-A[i]);
	}
	MAX=max(MAX, K-A[N-1]+A[0]);
	cout << K-MAX << endl;
}
