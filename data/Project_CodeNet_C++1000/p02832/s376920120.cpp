#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int M = 0;
	rep(i,N) {
		int a;
		cin >> a;
		if (a == M+1) M++;
	}

	if (M == 0) cout << -1 << endl;
	else cout << N-M << endl;

	return 0;
}
