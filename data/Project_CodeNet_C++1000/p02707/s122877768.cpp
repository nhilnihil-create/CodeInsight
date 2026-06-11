#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, tmp;
    cin >> n;
    vector<ll> v(n);

    for(int i = 1; i < n; ++i)
    {
        cin >> tmp;
        v[tmp - 1]++;
    }

    for(auto i: v) cout << i << "\n";
    return 0;
}