#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll tmp = n % k;
    cout << min(tmp, abs(k - tmp)) << endl;
}