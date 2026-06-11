#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	if (a > k)cout << k << endl;
	else if (a + b >= k) cout << a << endl;
	else cout << a - (k - a - b) << endl;
	return 0;
}