#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define no_of_test(x)   int x; cin>>x; while(x--)
const int mod = 1e9 + 7;
void very_fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int binary_exponentation(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}

int32_t main()
{
	very_fast();
//	no_of_test(x)
	{
		char s;
		cin >> s;
		//char w=
		cout << char(s + 1)  << "\n";
	}
	return 0;

}
