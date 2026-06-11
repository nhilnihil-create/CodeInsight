#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> S, T;
	int time, code;
	cin >> time;
	for (int i = 0; i < time; ++i) {
		cin >> code;
		S.push_back(code);
	}
	cin >> time;
	for (int i = 0; i < time; ++i) {
		cin >> code;
		T.push_back(code);
	}
	vector<int>::iterator heS, heT;
	int answer=0;
	for (heT = T.begin(); heT != T.end(); ++heT) {
		heS = S.begin();
		S.push_back(*heT);
		while (*heT != *heS) {
			++heS;
		}
		if (heS != S.end() - 1)++answer;
		S.pop_back();
	}
	cout << answer << endl;
	return 0;
}