#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	string w; cin >> w;
	for (char&c : w)c = tolower(c);
	string s;
	int cnt = 0;
	while (cin >> s, s != "END_OF_TEXT") {
		for (char&c : s)c = tolower(c);
		if (s == w)cnt++;
	}
	cout << cnt << endl;
}