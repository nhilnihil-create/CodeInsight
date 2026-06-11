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
vector<int>v1, v2;
int get(vector<int>v)
{	int cnt = 0;
	vector<int>k = v;
	sort(k.begin(), k.end());
	while (true)
	{	cnt++;
		if (k == v)
			return cnt;
		next_permutation(k.begin(), k.end());

	}
}

int32_t main()
{
	very_fast();
//	no_of_test(x)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v1.push_back(x);
		}
		for (int j = 0; j < n; j++)
		{
			int y;
			cin >> y;
			v2.push_back(y);
		}
		int a1 = get(v1);
		int a2 = get(v2);
		cout << abs(a1 - a2) << "\n";

	}
	return 0;

}
