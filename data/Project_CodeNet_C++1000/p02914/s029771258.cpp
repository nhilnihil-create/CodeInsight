#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

const int MAXN = 100010;

lint A[MAXN];
lint bas[60];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];

	lint B = 0;
	for(int i = 0; i < N; i++) B ^= A[i];
	for(int i = 0; i < N; i++) A[i] ^= A[i] & B;
	for(int i = 0; i < N; i++) for(int j = 59; j >= 0; j--) if(A[i] & (1ll << j)) {
		if(bas[j]) A[i] ^= bas[j];
		else {
			bas[j] = A[i];
			break;
		}
	}

	lint C = 0;
	for(int i = 59; i >= 0; i--) if(!(C & (1ll << i)) && bas[i]) 
		C ^= bas[i];

	cout << B + 2 * C;
	return 0;
}
