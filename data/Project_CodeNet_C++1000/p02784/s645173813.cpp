#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll h, n, tmp;
    cin >> h >> n;

    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        sum += tmp;
    }

    if(h - sum > 0) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}