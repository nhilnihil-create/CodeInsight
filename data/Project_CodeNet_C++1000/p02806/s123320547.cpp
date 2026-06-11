#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string> S;
	vector<int> T;
	int total_t = 0;
	for (int i = 0; i < N; i++) {
		string s;
		int t;
		cin >> s >> t;
		S.push_back(s);
		T.push_back(t);
		total_t += t;
	}

	string X;
	cin >> X;
	int diff_t = 0;
	for (int i = 0; i < N; i++) {
		diff_t += T[i];
		if (S[i] == X) {
			cout << total_t - diff_t << endl;
			return 0;
		}
	}
}
