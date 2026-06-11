#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[105];
int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	bool ok = true;
	for(long long i = 0; i < N; i++) {
		if(A[i] %2 == 0) {
			if(A[i] % 3 != 0 && A[i] % 5 != 0) {
				ok = false;
			}
		}
	}
	if(ok) {
		cout << "APPROVED" << endl;
	} else {
		cout << "DENIED" << endl;
	}
}
