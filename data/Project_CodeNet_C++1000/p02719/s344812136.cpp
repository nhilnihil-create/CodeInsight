#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll r = n % k;
    ll a = abs(r - k);
    cout << min(a, r) << endl;
    return 0;
}