#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = 'A' + (s[i] - 'A' + n) % 26;
    }
    cout << s << endl;

	return 0;
}