#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, k, d;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> x >> k >> d;
    if(x < 0) x = -x;
    if(x / d >= k)
    {
    	cout << x - k * d << endl;
    	return 0;
	}
	if(x / d % 2 == k % 2) cout << x % d << endl;
    else cout << d - x % d << endl;
	return 0;
}
