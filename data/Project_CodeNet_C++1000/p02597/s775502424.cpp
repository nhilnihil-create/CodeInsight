#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> white(n), red(n);
    for (int i = 0; i < n; i++) {
        if (i) {
            red[i] = red[i - 1];
            white[i] = white[i - 1];
        }
        if (s[i] == 'R')
            red[i]++;
        else
            white[i]++;
    }
    int resp = n - white[n - 1];
    for (int i = 0; i < n; i++)
        resp = min(resp, max(i + 1 - red[i], n - (i + 1) - (white[n - 1] - white[i])));
    cout << resp << endl;

	return 0;
}