#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int M;
    cin >> M;

    ll sumc = 0;
    ll sumd = 0;
    for (int i = 0; i < M; i++)
    {
        ll d, c;
        cin >> d >> c;
        sumc += c;

        sumd += d * c;
    }
    ll ans = sumc - 1 + (sumd - 1) / 9;
    cout << ans << endl;
    return 0;
}