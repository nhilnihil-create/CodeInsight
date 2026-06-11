#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	string s, t;
	int ans = 0;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}