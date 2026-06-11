#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
#define be(v) v.begin(), v.end()

int main() {
	string t; cin >> t; string s = t;
	int a =0; int b = 0;
	rep(i,t.length()) {
		if(t[i]=='?') {
			t[i] = 'D';
		}
	}
	cout << t << endl;
}
