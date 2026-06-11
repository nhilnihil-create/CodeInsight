#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N-1], B[N];
	for(int i=0;i<N;i++){
		B[i] = 0;
	}
	for(int i=0;i<N-1;i++){
		cin >> A[i];
		B[A[i] - 1]++;
	}
	for(int i=0;i<N;i++){
		cout << B[i] << endl;
	}
}
