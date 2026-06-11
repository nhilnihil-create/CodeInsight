#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i=0; i<s.length(); i++){
        char j = s[i];
        cout << (char) (((((int) j - 65) + n) % 26) + 65);
    }
    return;
}

int main() {
	solve();
	return 0;
}
