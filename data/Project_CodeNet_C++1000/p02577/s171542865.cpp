#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define maxN 200005

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
	string s;
	cin >> s;
	int n = 0;
	for (int i = 0; i < s.size(); i++) {
		n += (s[i] - '0');
	}
	if (n % 9) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}