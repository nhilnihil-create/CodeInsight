#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
typedef long long ll;

ll a[200005], b[200005];
ll n;

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;
    int l, r;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    if (n % 2) l = a[(n + 1) / 2], r = b[(n + 1) / 2];
    else l = a[n / 2] + a[n / 2 + 1], r = b[n / 2] + b[n / 2 + 1];
    cout << r - l + 1;
	return 0;
}
