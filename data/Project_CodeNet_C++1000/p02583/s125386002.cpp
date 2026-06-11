#include <bits/stdc++.h>
using namespace std;

int N, A[100];

int main(){
	cin >> N;
	for (int i = 0; i < N; i ++){
		cin >> A[i];
	}	

	long long result = 0;
	for (int i = 0; i < N; i ++){
		for (int j = i + 1; j < N; j ++){
			for (int k = j + 1; k < N; k ++){
				if (A[i] + A[j] > A[k]){
					if (A[j] + A[k] > A[i]){
						if (A[i] + A[k] > A[j]){
							if (A[i] != A[j] && A[j] != A[k] && A[i] != A[k]){
								result ++;
							}

							// cout << A[i] << " " << A[j] << A[k] << "\n";

						}
					}
				}
			}
		}
	}
	cout << result << "\n";
}