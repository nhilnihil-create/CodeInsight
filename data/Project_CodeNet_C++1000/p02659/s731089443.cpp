#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 50;
int main()
{
    std::ios::sync_with_stdio(false);
    ll a;
    long double b;
    cin >> a >> b;
    ll ans = ((b * 1000) * a) / 1000;
    cout << ans << endl;
    return 0;
}
