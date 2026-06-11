// ABC_141_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	string s;
	cin >> s;

	if(s.compare("Sunny") == 0) cout << "Cloudy" << "\n";
	else if(s.compare("Cloudy") == 0) cout << "Rainy" << "\n";
	else cout << "Sunny" << "\n";

	return 0;
}

