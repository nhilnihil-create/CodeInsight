#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int cnt = 0;
	for (int i=0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				string s = to_string(i) + to_string(j) + to_string(k);
				//cout << s << endl;

				int itr = 2;
				for (int l = 0; l < S.size(); l++) {
					if (S[l] == s[itr]) itr--;
					if (itr < 0) break;
				}

				if (itr < 0) cnt++;
			}
		}
	}

	cout << cnt << endl;
}