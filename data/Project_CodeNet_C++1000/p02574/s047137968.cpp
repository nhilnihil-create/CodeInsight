#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

void pf(int n, vector<int> &v) {
	int p = 2;
	while (p*p <= n) {
		if (n%p != 0) {
			p++;
			continue;
		}
		v.push_back(p);
		while (n%p == 0) n /= p;
	}
	if(n != 1) v.push_back(n);
}

int main(void){
	int N;
	cin >> N;

	vector<int> c(1'000'000);

	rep(i,N) {
		int a;
		cin >> a;
		vector<int> v;
		pf(a, v);
		for (int p : v) c[p]++;
	}
	
	bool pc = true;
	bool sc = true;
	rep(i,1'000'000) {
		if (c[i] < 2) continue;
		pc = false;
		if (c[i] == N) {
			sc = false;
			break;
		}
	}

	if (pc) cout << "pairwise coprime" << endl;
	else if (sc) cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
	
return 0;
}
