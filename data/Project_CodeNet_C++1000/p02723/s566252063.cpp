#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef  unsigned int uint;
typedef  long double ld;


int main()
{

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;


	if (s[2] == s[3] && s[4] == s[5])
		cout << "Yes\n";
	else
		cout << "No\n";


	return 0;
}