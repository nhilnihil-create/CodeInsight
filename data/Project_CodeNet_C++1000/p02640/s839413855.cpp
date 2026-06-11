#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
//#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
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
	//no_of_test(x)
	{
		int a, b;
		cin >> a >> b;
		if (b % 2 == 0)
		{
			if (b >= 2 * a && b <= 4 * a)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}



