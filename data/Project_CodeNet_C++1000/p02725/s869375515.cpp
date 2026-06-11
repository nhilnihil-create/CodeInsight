#include<bits/stdc++.h>
using namespace std;

long long K, N;
long long A[200005];
// i -> i + 1
long long diff[200005];

int main(){
	cin >> K >> N;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	for(long long i = 0; i < N - 1; i++) {
		diff[i] = A[i+1] - A[i];
	}
	//i = N-1
	diff[N-1] = A[0] + K - A[N-1];


	long long sumi = 0;
	long long maxi = 0;
	for(long long i = 0; i < N; i++) {
		sumi += diff[i];
		maxi = max(maxi, diff[i]);
	}
	cout << sumi - maxi << endl;





}