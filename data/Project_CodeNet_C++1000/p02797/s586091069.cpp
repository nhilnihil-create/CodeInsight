#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MAXVAL = 1000000000;

int main() {
	ll N, K, S;
	cin >> N >> K >> S;

	for (int ii = 0; ii < K; ++ii){
		cout << S << " ";
	}
	ll rem = (S == MAXVAL) ? 1 : MAXVAL;
	for (int ii = K; ii < N; ++ii){
		cout << rem << " ";
	}	

	cout << "\n";

	return 0;
}
