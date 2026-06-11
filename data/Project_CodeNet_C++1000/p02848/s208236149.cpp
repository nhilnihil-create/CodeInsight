#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	rep(i, s.size()) {
		int x = s[i] - 'A'; //'A'=65、'B'=66...、'Z'=90。'A' = 0, 'B' = 1... 'Z' = 26 とするため、s[i] - 'A'。
		x = (x + n) % 26; //26を超えた数値になっても、またAからになるように
		char ans = x + 'A'; //元々は'A'=65、'B'=66...、'Z'=90 であるため、+ 'A' つまり、+65 をして文字の置き換え
		cout << ans;
	}
	cout << endl;
}