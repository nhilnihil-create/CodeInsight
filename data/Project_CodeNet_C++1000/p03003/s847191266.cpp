#include <iostream>
#include <vector>

using namespace std;

typedef long long INT;

static INT MOD = 1000000007;

int main(void) {
    INT N, M;
    cin >> N >> M;

    vector<INT> S(N), T(M+1);

    for(INT i=0; i<N; ++i) {
	cin >> S[i];
    }
	
    for(INT i=0; i<M; ++i) {
	cin >> T[i];
    }

    vector<INT> X(N+1, 0);
    X[0] = 1;

    for(INT m=0; m<M; ++m) {
	INT t = T[m], x = 1;
	
	for(INT n=0; n<N; ++n) {
	    INT s = S[n], prevX = X[n+1];

	    if (t == s) {
		X[n+1] = (X[n+1] + x)%MOD;
	    }

	    x =  (x + prevX)%MOD;
	}
    }

    INT sum = 0;
    for(INT i=0; i<N+1; ++i) {
	sum = sum + X[i];
    }

    cout << sum%MOD << endl;
}

