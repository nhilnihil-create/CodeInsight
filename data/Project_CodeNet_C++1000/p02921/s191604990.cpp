#include <iostream>
#include <string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	string s, t;
	int i, ans=0;
	cin >> s >> t;
	for (int i = 0; i < 3; i++) {
		if (s[i] == t[i])ans++;
	}
	cout << ans << endl;
	
}
