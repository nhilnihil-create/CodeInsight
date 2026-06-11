#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a, b;
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        sum1 += b;
        sum2 += a * b;
    }
    ll ans;
    ans = sum1 - 1 + (sum2 - 1) / 9;
    cout << ans  << endl;
}