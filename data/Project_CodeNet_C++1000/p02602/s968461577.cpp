#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector <int> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}

	bool ok = true;
	for (int ii = 0; ii < N - K; ++ii){
		if (A[ii] >= A[ii+K]){
			cout << "No" << "\n";
		} else{
			cout << "Yes" << "\n";			
		}
	}	


	return 0;
}
