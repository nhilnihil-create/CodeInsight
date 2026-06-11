#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

ll a, b, c, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;
	ll res = max(max(a * c, a * d), max(b * d, c * b));
	if ((a <= 0 && 0 <= b) || (c <= 0 && 0 <= d))
		res = max(res, 0LL);
	cout << res;
}