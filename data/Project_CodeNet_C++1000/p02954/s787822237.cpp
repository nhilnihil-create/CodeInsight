#include<bits/stdc++.h>
using namespace std;
int main () {
	string s;
	cin >> s;
	int n = s.length();
	long long a[100500]={0};
	int r, l;
	r=0, l=0;
	for (int i=0; i<n; i++) {
		if (s[i]=='R') r++,l=0;
		else {
			a[i-1]+=ceil(1.0*r/2);
			a[i]+=floor(1.0*r/2);
			l++; r=0;
		}
	}
	r=0, l=0;
	for (int i=n; i>=0; i--) {
		if (s[i]=='L') l++,r=0;
		else {
			a[i+1]+=ceil(1.0*l/2);
			a[i]+=floor(1.0*l/2);
			r++; l=0;
		}
	}
	for (int i = 0; i<n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}