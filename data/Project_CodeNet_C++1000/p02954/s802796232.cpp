#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

void printVec(vector<int> vec) {
	rep(i, vec.size())cout << vec[i] << " ";
}



int main() {
	string S; cin >> S;
	vector<int> num(S.size(), 1);
	vector<pair<int, int>> sets;

	int countR = 1;
	int countL = 1;
	bool isR = true;

	rep(i, S.size()-1) {
		if (S[i] == S[i + 1]) {
			if (isR)++countR;
			else countL++;
		}
		else {
			if (!isR) {
				sets.push_back(make_pair(countR, countL));
				countR = countL = 1;
			}
			isR = !isR;
		}
	}
	sets.push_back(make_pair(countR, countL));

	rep(i, sets.size()) {
		rep(j, sets[i].first - 1)cout << 0 << " ";
		int num = sets[i].first + sets[i].second;
		//cout << num << endl;
		if (num % 2 == 0) {
			cout << num / 2 << " " << num / 2 << " ";
		}
		else {
			if (sets[i].first > sets[i].second) {
				if ((sets[i].first - 1) % 2 != 0)cout << num / 2 << " " << (num / 2) + 1 << " ";
				else cout << (num / 2) + 1 << " " << num / 2 << " ";
			}
			else {
				if ((sets[i].second - 1) % 2 != 0)cout << (num / 2) + 1 << " " << num / 2 << " ";
				else cout << num / 2 << " " << (num / 2) + 1 << " ";
			}
		}
		rep(j, sets[i].second - 1)cout << 0 << " ";
	}
}