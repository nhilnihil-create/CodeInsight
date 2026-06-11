#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	int ans = 0;
	while(A >= B){
		B *= 2;
		ans++;
	}
	while(B >= C){
		C *= 2;
		ans++;
	}

	if (ans <= K){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}


	return 0;
}
