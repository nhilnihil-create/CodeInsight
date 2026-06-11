#include <bits/stdc++.h>
using namespace std;

int n;

#define N 1005

string s[N], X;
int t[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> s[i] >> t[i];
    cin >> X;
    int pos = -1;
    for (int i = 1; i <= n; i ++) if (s[i] == X) pos = i;
    int ans = 0;
    for (int i = pos+1; i <= n; i ++) ans += t[i];
    cout << ans << endl;
	return 0;
}
