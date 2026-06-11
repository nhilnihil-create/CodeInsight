#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main () {
int A, B, C; cin >> A >> B >> C;
int K; cin >> K;

// A < B < C
for (int i = 0; i < K; i++){
	if (!(A < B)) {
  	B *= 2;
	} else if(!(B < C)) {
  	C *= 2;
	} else {
		C *= 2;
	}
}
if (A < B && B < C)
	cout << "Yes" << endl;
else
	cout << "No" << endl;

	return 0;
}
