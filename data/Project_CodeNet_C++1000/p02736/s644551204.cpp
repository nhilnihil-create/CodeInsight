#include <bits/stdc++.h>
#define forsn(i, s, n) for(int i = s; i < n; ++i)
#define forn(i, n) for(int i = 0; i < n; ++i)
using namespace std;

const int maxn = 2e6;
int val[maxn];
void init() {
	for(int k = 2; k < maxn; k*=2) {
		for(int i = k; i < maxn; i += k) val[i]++;
	}
	forsn(i, 1, maxn) val[i] += val[i-1];
}

int main() {
	init();
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<int> orig(n);
	bool ones = false;
	forn(i, n) if(s[i] == '2') ones = true;
	int total = 0;
	/*
	forn(i, n) {
		forn(j, i+1) cout << (val[i] - val[j] - val[i-j] == 0);
		cout << endl;
	}*/
	forn(i, n) total ^= (s[i] - '1') * int(val[n-1] == val[n-i-1] + val[i]);
	if(ones) total &= 1;
	cout << total << "\n";
}
