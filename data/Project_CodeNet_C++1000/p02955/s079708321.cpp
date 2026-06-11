#include        <bits/stdc++.h>
using namespace std;

int     main() {
	int N;
	long K;
	cin >>N >>K;
	int S=0;
	vector<int> A(N);
	for (int i=0; i<N; i++) {
		cin >> A.at(i);
		S += A.at(i);
	}
	vector<int> B(0);
	for (int i=1; i<=sqrt(S); i++) {
		if (0==S%i) {
			B.push_back(i);
			B.push_back(S/i);
		}
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	//
	int j=B.size();
	vector<int> M(N);
	while (true) {
		j--;
		if (j<0) break;
		int BB=B.at(j);
		for (int i=0; i<N; i++) {
			M.at(i)=A.at(i)%BB;
		}
		sort(M.begin(), M.end());
		int L=0;
		int R=N-1;
		long KKK=0;
		int SSS=0;
		if (0<M.at(R)) {
			SSS +=M.at(L)-(BB-M.at(R));
			KKK +=M.at(L);
			while (R-L>1) {
				if (SSS<0) {
					L++;
					SSS += M.at(L);
					KKK += M.at(L);
				} else {
					R--;
					SSS -= BB-M.at(R);
				}
			}
		}
		if (KKK<=K) {
			cout <<BB <<endl;
			return 0;
		}
	}
	return 0;
};
