#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N], B[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
		B[A[i] - 1] = i + 1;
	}
	for(int i=0;i<N;i++){
		cout << B[i];
		if(i != N-1)cout << " ";
	}
	cout << endl;
}