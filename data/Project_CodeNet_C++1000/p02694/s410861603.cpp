#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
///                    BISMILLAHIR RAHMANIR RAHIM

int main()
{
  ll x;
    cin >> x;
    ll t = 100;
    ll ans = 0;
    while (t < x) {
        t += t / 100;
        ans++;
    }
    cout << ans;
    return 0;
}

/// A L H A M D U L I L L A H
