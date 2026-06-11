#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll res = 0;
    for (ll i = K; i <= N + 1; i++)
    { // calculate over k.
        ll pattern = i * (2 * N - i + 1) / 2 - i * (i - 1) / 2 + 1;
        res = (res + pattern) % 1000000007;
    }
    cout << res;
}