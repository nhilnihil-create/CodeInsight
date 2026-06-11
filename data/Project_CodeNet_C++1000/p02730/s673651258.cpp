#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 回文ならばtrueを返す関数
bool Get_is_palindrome(string s) {
	bool result = true;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			result = false;
		}
	}
	return result;
}

int main() {

	string s; cin >> s;
	int n = s.size();
	string left = s.substr(0, (n - 1) / 2);
	string  right = s.substr((n + 1) / 2);
	string ans = "No";
	if (Get_is_palindrome(s) && Get_is_palindrome(left) && Get_is_palindrome(right)) {
		ans = "Yes";
	}
	cout << ans << endl;
    return 0;
}