#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n; cin >> n;
	string s; cin >> s;

	string news = "";

	for (char c : s) {
		int a = (int)c;

		if (a + n > (int)'Z') {
			int d = (a + n) - (int)'Z' + (int)'A' - 1;
			char newc = (char)d;
			news += newc;
			continue;
		}

		a += n;
		char newc = (char)a;
		news += newc;
	}

	cout << news;
	return 0;

}