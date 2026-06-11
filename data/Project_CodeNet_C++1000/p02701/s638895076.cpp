#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    string tmp;
    cin >> n;

    unordered_map<string, ll> map;

    for(ll i = 0; i < n; ++i)
    {
        cin >> tmp;
        map[tmp]++;
    }

    cout << map.size() << "\n";
    return 0;
}