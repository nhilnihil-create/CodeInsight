#include "bits/stdc++.h"
using namespace std;
const int INF = 1 << 30;

int main() {
	int N, M; 
	string S;
	cin >> N >> M >> S;
	vector<int>Ans;
	int now = N;
	while (now != 0) {
		bool b = false;
		for (int n = M; n > 0; --n) {
			if (now -n < 0){
				continue;
			}
			if ('1' != S[now- n]) {
				now -= n;
				Ans.push_back(n);
				b = true;
				break;
			}
		}
		if (b == false) {
			cout << "-1" << endl;
			return 0;
		}
	}
	reverse(Ans.begin(),Ans.end());
	for (int n = 0;n < Ans.size();++n) {
		if (0 != n) {
			cout << " ";
		}
		cout << Ans[n];
	}
	return 0;
}

