#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

int main()
{
	faster;
	
	ll a,b,d;
	cin >> a;
	char c;
	cin >> b >> c >> d;
	b *= 100;
	b += d;

	cout << (ll)((a * b)/100) << endl;

	return 0;
}