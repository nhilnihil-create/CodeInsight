#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    cout << max(max(a * c, b * c), max(a * d, b * d)) << endl;
	return 0;
}
