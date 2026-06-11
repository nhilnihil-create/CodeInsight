#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	string S;
	cin >> S;

	string dstr = S.substr(0, 1);
	string str = dstr;
	vector<string> vs;
	if (S.length() == 1) {
		vs.push_back(str);
	}

	for (int i = 1; i < S.length(); i++) {
		while (i < S.length() && dstr == S.substr(i, 1)) {
			str += dstr;
			i++;
		}
		vs.push_back(str);
		if (i < S.length()){
			dstr = S.substr(i, 1);
			str = dstr;
		}
		if (i == S.length() - 1) {
			vs.push_back(str);
		}
	}

	vector<long long> a(S.length() + 1, -1);
	int ind = 0;
	a[ind] = 0;

	for (int i = 0; i < vs.size(); i++) {
		if (vs[i][0] == '<') {
			for (int j = 0; j <= vs[i].length(); j++) {
				a[ind + j] = j;
			}
		}
		else {
			for (int j = 0; j <= vs[i].length(); j++) {
				a[ind + j] = max(a[ind + j], (long long)vs[i].length() - (long long)j);
			}
		}
		ind += vs[i].length();
	}

	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
	}

	cout << ans << endl;

	return 0;
}