#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);

    ll n,k;
    cin >> n >> k;
    n %= k;
    ll a = n;
    ll b = abs(n-k);
    cout << min(a,b);
    return 0;
}
