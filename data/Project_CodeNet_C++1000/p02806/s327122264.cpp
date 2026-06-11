#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string> S;
	vector<int> T;
	for (int i = 0; i < N; i++) {
		string s;
		int t;
		cin >> s >> t;
		S.push_back(s);
		T.push_back(t);
	}

	string X;
	cin >> X;

	bool flag = false;
	int total = 0;
	for (int i = 0; i < N; i++) {
		if (flag) {
			total += T[i];
		}

		if (X == S[i]) {
			flag = true;
		}
	}

	cout << total << endl;
}


