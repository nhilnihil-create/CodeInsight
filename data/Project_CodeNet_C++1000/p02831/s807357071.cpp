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
	int ans =  (a * b) / __gcd(a, b);
	cout << ans << endl;
	return 0;
}

//!