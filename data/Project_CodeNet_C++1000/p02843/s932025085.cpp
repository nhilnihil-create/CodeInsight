#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int X;
	cin >> X;
	int N = X/100;
	X -= 100*N;
	int M = 0;
	for (int i = 5; i >0; i--) {
		M += X/i;
		X -= i*(X/i);
	}
	if (X==0 && M<=N) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
