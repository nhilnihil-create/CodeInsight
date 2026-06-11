#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, C;
string S;

int A[200005], B[200005], P[200005], sum[200005];

int main(void) {

	cin >> N >> K >> C;
	cin >> S;

	S = "$" + S + "$";

	for (int i = 1; i <= N; i++) {
		if (S[i] == 'o') {
			if (i - C - 1 >= 1) {
				A[i] = A[i - C - 1] + 1;
			}
			else { A[i] = 1; }
		}
		else { A[i] = A[i - 1]; }
	}

	

	for (int i = N; i >= 1; i--) {
		if (S[i] == 'o') {
			if (i + C + 1 <= N) { B[i] = B[i + C + 1] + 1; }
			else { B[i] = 1; }
		}
		else {
			B[i] = B[i + 1];
		}
	}


	if (C > 0) {
		for (int i = 1; i + C + 1 <= N; i++) {
			if (A[i] + B[i + C + 1] >= K) {
				for (int j = i + 1; j <= i + C; j++) { P[j] = 1; }
			}
		}

		for (int i = 1; i <= C; i++) {
			if (B[i + 1] >= K) { P[i] = 1; }
		}

		for (int i = N - C + 1; i <= N; i++) {
			if (A[i - 1] >= K) { P[i] = 1; }
		}



		/*for (int i = 1; i + C + 1 <= N; i++) {
			if (A[i] + B[i + C + 1] >= K) { sum[i + 1]++; sum[i + C + 1]--; }
		}


		for (int i = 1; i <= N; i++) {
			sum[i] += sum[i - 1];
		}

		for (int i = 1; i <= N; i++) {
			P[i] += sum[i];
		}*/

	}
	else {
		for (int i = 1; i <= N; i++) {
			if (A[i - 1] + B[i+1] >= K) { P[i] = 1; }
		}
	}

/*	for (int i = 1; i <= N; i++) {
	cout << "A[" << i << "]= " << A[i] <<" B["<<i<<"]= "<<B[i]<< " P["<<i<<"]= "<< P[i] <<" sum["<<i<<"]= "<<sum[i]<< endl;
	}*/


	for (int i = 1; i <= N; i++) {
		if (S[i] == 'o' && P[i] <= 0) { cout << i << endl; }
	}
	
	return 0;
}