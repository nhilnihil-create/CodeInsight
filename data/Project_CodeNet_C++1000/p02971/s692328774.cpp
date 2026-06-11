#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N], B[N];
	rep(i,N){
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B,B+N);
	rep(i,N) {
		if (A[i] == B[N-1]) cout << B[N-2] << endl;
		else cout << B[N-1] << endl;
	}

	return 0;
}
