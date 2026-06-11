#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	string a, b, x;
	int m, n;
	cin >> a >> b >> m >> n >> x;
	if(x == a) cout << m - 1 << " " << n << endl;
	else if(x == b) cout  << m << " " << n -1 << endl ;	
	return 0;
}
