#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int a[N+1], w[N+1];
	rep(i,N+1) {
		a[i] = 0;
		w[i] = 0;
	}

	rep(i,M) {
		int p;
		string s;
		cin >> p >> s;
		if (s == "AC") {
			a[p]++;
		}
		else {
			if (a[p] > 0) continue;
			else w[p]++;
		}
	}

	int Na = 0, Nw=0;
	for (int i = 1; i <= N; i++) {
		if (a[i]>0) {
			Na++;
			Nw += w[i];
		}
	}

	cout << Na << endl;
	cout << Nw << endl;

	return 0;
}
