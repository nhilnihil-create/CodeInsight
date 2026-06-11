#include <bits/stdc++.h>
using namespace std;

int main(){
	int K, N;
	cin >> K >> N;
	int A[N];
	int sa[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N-1;i++){
		sa[i] = A[i+1] - A[i];
	}
	sa[N-1] = A[0] + K - A[N-1];
	int MA = 0;
	for(int i=0;i<N;i++){
		MA = max(MA, sa[i]);
	}
	cout << K - MA << endl;
}