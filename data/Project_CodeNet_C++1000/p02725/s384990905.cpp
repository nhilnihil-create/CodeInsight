#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int K, N;
	cin >> K >> N;
	int A[N];
	rep(i,N) cin >> A[i];

	int dmax = A[0] + K - A[N-1];
	rep(i,N-1){
		dmax = max(dmax, A[i+1]-A[i]);
	}
	cout << K - dmax << endl;
	return 0;
}
