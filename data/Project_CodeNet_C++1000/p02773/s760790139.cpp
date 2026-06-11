#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> S(N);
	rep(i,N) cin >> S[i];
	sort(S.begin(),S.end());

	int count = 1;
	int count_max = 1;
	set<string> st;
	st.insert(S[0]);
	for (int i = 1; i < N; i++) {
		if (S[i] == S[i-1]) {
			count++;
		}
		else count = 1;

		if (count == count_max) {
			st.insert(S[i]);
		}
		if (count > count_max) {
			st.clear();
			st.insert(S[i]);
			count_max = count;
		}

	}

	for (string s : st) {
		cout << s << endl;
	}


	return 0;
}
