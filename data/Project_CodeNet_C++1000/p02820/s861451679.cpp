#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k, r, s, p;
	string t;
	cin >> n >> k >> r >> s >> p >> t;
	int win[n] = {};
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		if(i < k) {
			if(t[i] == 'r') res += p;
			else if(t[i] == 's') res += r;
			else res += s;
			win[i] = 1;
		}
		else {
			if(win[i-k] && t[i] == t[i-k]) continue;
			if(t[i] == 'r') res += p;
			else if(t[i] == 's') res += r;
			else res += s;
			win[i] = 1;
		}
	}
	cout << res << endl;
	return 0;
}
