#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
using namespace std;

int main() {
	
	string s, t;
	cin >> s >> t;


	int ans = 10000, tmp = 0;;
	for (int i = 0;i < s.length()-t.length()+1;i++) {
		for (int j = 0;j < t.length();j++) {
			if (s[i + j] != t[j]) tmp++;
		}
		ans = min(ans, tmp);
		tmp = 0;
	}

	cout << ans << endl;

	return 0;
}