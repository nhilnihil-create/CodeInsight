#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int		main(void)
{
	int a;
	string s;

	cin >> a;
	cin >> s;
	if (a >= 3200)
		cout << s << endl;
	else
		puts("red");
}

