#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e5 + 5;


int32_t main()
{
	GO;
	int a, b;
	cin >> a >> b;
	if (a != 1 && b != 1)
		cout << 1 << endl;
	else if (a != 2 && b != 2)
		cout << 2 << endl;
	else
		cout << 3 << endl;

	return 0;
}

//!