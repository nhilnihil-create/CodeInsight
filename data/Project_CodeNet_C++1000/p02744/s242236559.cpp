#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF (1e9)
#define PI (acos(-1))

int TypeCount(string s) {
	string save = "";
	for (int i = 0; i < s.size(); i++) {
		if (save.find(s[i]) == string::npos) save += s[i];
	}
	return save.size();
}

int main() {
	int n, type;
	cin >> n;
	string ans;
	vector<vector<string>> table(n, vector<string>(0));

	table[0].push_back("a");
	if(n == 1) cout << "a" << endl;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < table[i-1].size(); j++) {
			type = TypeCount(table[i-1][j]);
			for (int k = 0; k < type+1; k++) {
				ans = table[i-1][j];
				ans.push_back('a' + k);
				table[i].push_back(ans);
				if(i == n-1) cout << ans << endl;
			}
		}
	}

	return 0;
}