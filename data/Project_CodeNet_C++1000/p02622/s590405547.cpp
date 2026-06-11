#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int solve() {
    int cnt = 0;
    string s, t; cin >> s >> t;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
