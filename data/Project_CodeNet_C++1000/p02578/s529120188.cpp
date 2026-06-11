#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, A[200000];

int main(){
	cin >> N;
	for (int i = 0; i < N; i ++){
		cin >> A[i];
	}
	int mx = 0;
	long long result = 0;
	for (int i = 0; i < N; i ++){
		// cout << max(0, mx - A[i]) << " ";
		result += max(0, mx - A[i]);
		mx = max(mx, A[i]);
	}
	cout << result << "\n";
}