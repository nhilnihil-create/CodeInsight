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
	if (1 <= a && a <= 9 && 1 <= b && b <= 9)
		cout << a * b << endl;
	else
		cout << -1 << endl;
	return 0;
}

//!