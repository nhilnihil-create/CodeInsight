#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;

    for(ll c = 1; c <= N - 1; c++){
        ans += (N-1)/c;
    }

    cout << ans << endl;

    return 0;
}