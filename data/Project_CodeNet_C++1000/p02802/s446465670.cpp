#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<int> p(m);
	vector<string> s(m);
	vector<bool> isACExist(n, false);
	vector<int> ACIndex(n, -1);

	for (int i = 0; i < m; i++) {
		cin >> p[i] >> s[i];
		p[i]--;
		if (!isACExist[p[i]]) {
			if (s[i] == "AC") {
				isACExist[p[i]] = true;
				ACIndex[p[i]] = i;
			}
		}
	}
	int ansAC = 0;
	int ansWA = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == "WA" && isACExist[p[i]] && i < ACIndex[p[i]]) {
			ansWA++;
		}
		if (s[i] == "AC" && i == ACIndex[p[i]]) {
			ansAC++;
		}

	}	
	cout << ansAC << " " << ansWA << endl;
    return 0;
}